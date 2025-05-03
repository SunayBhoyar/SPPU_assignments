%%cu
#include <iostream>     // For input and output operations
#include <vector>       // For using dynamic arrays (vectors) - although not strictly needed here, it's a common practice
#include <chrono>       // For measuring execution time
#include <cuda.h>       // CUDA runtime library

using namespace std;
using namespace std::chrono;

// CUDA kernel for element-wise vector addition
__global__ void add(int* A, int* B, int* C, int size) {
    // Calculate the global thread ID
    int tid = blockIdx.x * blockDim.x + threadIdx.x;

    // Check if the thread ID is within the bounds of the vector size
    if (tid < size) {
        // Perform element-wise addition: C[tid] = A[tid] + B[tid]
        C[tid] = A[tid] + B[tid];
    }
}

// Function to initialize a vector with default values or user input
void initialize(int* vector, int size, bool useDefault = false) {
    if (useDefault) {
        // Default initialization: fill the vector with increasing numbers starting from 1
        for (int i = 0; i < size; i++) {
            vector[i] = i + 1;
        }
    } else {
        // Manual input: prompt the user to enter each element of the vector
        for (int i = 0; i < size; i++) {
            cout << "Enter element " << i + 1 << " of the vector: ";
            cin >> vector[i];
        }
    }
}

// Function to print the elements of a vector
void print(int* vector, int size) {
    for (int i = 0; i < size; i++) {
        cout << vector[i] << " ";
    }
    cout << endl; // Move to the next line after printing all elements
}

// Sequential CPU implementation of vector addition
void sequentialAddition(int* A, int* B, int* C, int size) {
    // Iterate through each element of the vectors
    for (int i = 0; i < size; i++) {
        // Perform element-wise addition
        C[i] = A[i] + B[i];
    }
}

int main() {
    int N;             // Size of the vectors
    char choice;       // User's choice for default input
    bool useDefault = false; // Flag to indicate whether to use default input

    // Ask the user if they want to use default vector size and elements
    cout << "Use default vector size (8) and elements? (y/n): ";
    cin >> choice;

    // Set the vector size and the useDefault flag based on the user's input
    if (choice == 'y' || choice == 'Y') {
        N = 8;
        useDefault = true;
    } else {
        cout << "Enter the size of the vectors: ";
        cin >> N;
    }

    // Declare pointers to the host (CPU) memory for the vectors
    int* A, * B, * C;

    int vectorSize = N;                     // Store the size of the vector
    size_t vectorBytes = vectorSize * sizeof(int); // Calculate the size in bytes

    // Allocate memory on the host for the input and output vectors
    A = new int[vectorSize];
    B = new int[vectorSize];
    C = new int[vectorSize];

    // Initialize vectors A and B using the initialize function
    cout << "Initializing Vector A:\n";
    initialize(A, vectorSize, useDefault);
    cout << "Initializing Vector B:\n";
    initialize(B, vectorSize, useDefault);

    // Print the input vectors
    cout << "Vector A: ";
    print(A, N);
    cout << "Vector B: ";
    print(B, N);

    // Declare pointers to the device (GPU) memory for the vectors
    int* X, * Y, * Z;
    // Allocate memory on the device for the input and output vectors
    cudaMalloc(&X, vectorBytes);
    cudaMalloc(&Y, vectorBytes);
    cudaMalloc(&Z, vectorBytes);

    // Copy vectors A and B from host to device
    cudaMemcpy(X, A, vectorBytes, cudaMemcpyHostToDevice);
    cudaMemcpy(Y, B, vectorBytes, cudaMemcpyHostToDevice);

    // Define the number of threads per block
    int threadsPerBlock = 256;
    // Calculate the number of blocks needed for the grid
    int blocksPerGrid = (N + threadsPerBlock - 1) / threadsPerBlock;

    // Perform sequential vector addition on the CPU
    auto start = high_resolution_clock::now();
    sequentialAddition(A, B, C, N);
    auto stop = high_resolution_clock::now();
    auto seq_duration = duration_cast<microseconds>(stop - start);

    cout << "Sequential Addition: ";
    print(C, N);

    // Perform parallel vector addition on the GPU
    start = high_resolution_clock::now();
    // Launch the CUDA kernel on the device
    add<<<blocksPerGrid, threadsPerBlock>>>(X, Y, Z, N);
    // Copy the result vector C from device to host
    cudaMemcpy(C, Z, vectorBytes, cudaMemcpyDeviceToHost);
    stop = high_resolution_clock::now();
    auto par_duration = duration_cast<microseconds>(stop - start);

    cout << "Parallel Addition: ";
    print(C, N);

    // Print the execution times for sequential and parallel addition
    cout << "Sequential Addition Time: " << seq_duration.count() << " microseconds" << endl;
    cout << "Parallel Addition Time: " << par_duration.count() << " microseconds" << endl;

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