%%writefile matrix.cu
#include <iostream> // For input and output operations
#include <cuda.h>   // CUDA runtime library
#include <chrono>  // For measuring execution time

using namespace std;
using namespace std::chrono;

// CUDA kernel for matrix multiplication
__global__ void multiply(int* A, int* B, int* C, int M, int N, int K) {
    // Calculate the row index for the current thread
    int row = blockIdx.y * blockDim.y + threadIdx.y;
    // Calculate the column index for the current thread
    int col = blockIdx.x * blockDim.x + threadIdx.x;

    // Check if the current thread is within the bounds of the output matrix
    if (row < M && col < K) {
        int sum = 0;
        // Iterate through the elements of the rows of A and columns of B
        for (int i = 0; i < N; i++) {
            // Perform the multiplication and accumulate the sum
            sum += A[row * N + i] * B[i * K + col];
        }
        // Store the result in the corresponding element of the output matrix C
        C[row * K + col] = sum;
    }
}

// Function to initialize a matrix with default values or user input
void initialize(int* matrix, int rows, int cols, bool useDefault = false) {
    if (useDefault) {
        // Default initialization for 4x4 matrices
        for (int i = 0; i < rows * cols; i++) {
            matrix[i] = i + 1;  // Simple pattern: 1, 2, 3, ...
        }
    } else {
        // Manual input from the user
        for (int i = 0; i < rows * cols; i++) {
            cout << "Enter element " << i + 1 << ": ";
            cin >> matrix[i];
        }
    }
}

// Function to print the elements of a matrix
void print(int* matrix, int rows, int cols) {
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            cout << matrix[row * cols + col] << " ";
        }
        cout << '\n'; // Move to the next row after printing all columns
    }
    cout << '\n'; // Add an extra newline for better readability
}

// Sequential CPU implementation of matrix multiplication
void sequentialMultiply(int* A, int* B, int* C, int M, int N, int K) {
    for (int i = 0; i < M; i++) {        // Iterate through rows of A
        for (int j = 0; j < K; j++) {    // Iterate through columns of B (and rows of C)
            int sum = 0;
            for (int k = 0; k < N; k++) { // Iterate through columns of A (and rows of B)
                sum += A[i * N + k] * B[k * K + j];
            }
            C[i * K + j] = sum;          // Store the result in C
        }
    }
}

int main() {
    int M, N, K;
    char choice;
    bool useDefault = false;

    cout << "Use default 4x4 matrices? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        M = 4;
        N = 4;
        K = 4;
        useDefault = true;
    } else {
        cout << "Enter the number of rows of the first matrix: ";
        cin >> M;
        cout << "Enter the number of columns of the first matrix (and rows of the second): ";
        cin >> N;
        cout << "Enter the number of columns of the second matrix: ";
        cin >> K;
    }

    // Allocate memory on the host (CPU)
    int* A = new int[M * N];
    int* B = new int[N * K];
    int* C = new int[M * K];

    // Initialize the matrices A and B
    cout << "Initializing Matrix A:\n";
    initialize(A, M, N, useDefault);

    cout << "Initializing Matrix B:\n";
    initialize(B, N, K, useDefault);

    // Print the input matrices
    cout << "Matrix A: \n";
    print(A, M, N);

    cout << "Matrix B: \n";
    print(B, N, K);

    // Allocate memory on the device (GPU)
    int* X, * Y, * Z;
    cudaMalloc(&X, M * N * sizeof(int));
    cudaMalloc(&Y, N * K * sizeof(int));
    cudaMalloc(&Z, M * K * sizeof(int));

    // Copy matrices A and B from host to device
    cudaMemcpy(X, A, M * N * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(Y, B, N * K * sizeof(int), cudaMemcpyHostToDevice);

    // Define the number of threads per block
    int THREADS = 16;

    // Calculate the number of blocks needed in each dimension
    int BLOCKS_X = (K + THREADS - 1) / THREADS;
    int BLOCKS_Y = (M + THREADS - 1) / THREADS;

    // Define the dimensions of the thread block and the grid of blocks
    dim3 threads(THREADS, THREADS);
    dim3 blocks(BLOCKS_X, BLOCKS_Y);

    // Perform sequential matrix multiplication on the CPU
    auto start = high_resolution_clock::now();
    sequentialMultiply(A, B, C, M, N, K);
    auto stop = high_resolution_clock::now();
    auto seq_duration = duration_cast<microseconds>(stop - start);

    cout << "Sequential Multiplication of matrix A and B: \n";
    print(C, M, K);

    // Perform parallel matrix multiplication on the GPU
    start = high_resolution_clock::now();
    multiply<<<blocks, threads>>>(X, Y, Z, M, N, K);
    cudaDeviceSynchronize(); // Wait for the GPU kernel to complete
    // Copy the result matrix C from device to host
    cudaMemcpy(C, Z, M * K * sizeof(int), cudaMemcpyDeviceToHost);
    stop = high_resolution_clock::now();
    auto par_duration = duration_cast<microseconds>(stop - start);

    cout << "Parallel Multiplication of matrix A and B: \n";
    print(C, M, K);

    // Print the execution times and the speedup
    cout << "Sequential Multiplication Time: " << seq_duration.count() << " microseconds" << endl;
    cout << "Parallel Multiplication Time: " << par_duration.count() << " microseconds" << endl;
    cout << "Speedup: " << (float)seq_duration.count() / par_duration.count() << "x" << endl;

    // Free the allocated memory on the host
    delete[] A;
    delete[] B;
    delete[] C;

    // Free the allocated memory on the device
    cudaFree(X);
    cudaFree(Y);
    cudaFree(Z);

    return 0;
}