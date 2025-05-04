%%writefile matrix.cu
#include <iostream>
#include <cuda.h> 
#include <chrono> 

using namespace std;
using namespace std::chrono;

__global__ void multiply(int* A, int* B, int* C, int M, int N, int K) {
    int row = blockIdx.y * blockDim.y + threadIdx.y;
    int col = blockIdx.x * blockDim.x + threadIdx.x;
    if (row < M && col < K) {
        int sum = 0;
        for (int i = 0; i < N; i++) {
            sum += A[row * N + i] * B[i * K + col];
        }
        C[row * K + col] = sum;
    }
}

void print(int* matrix, int rows, int cols) {
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            cout << matrix[row * cols + col] << " ";
        }
        cout << '\n';
    }
    cout << '\n';
}

void sequentialMultiply(int* A, int* B, int* C, int M, int N, int K) {
    for (int i = 0; i < M; i++) {   
        for (int j = 0; j < K; j++) {  
            int sum = 0;
            for (int k = 0; k < N; k++) { 
                sum += A[i * N + k] * B[k * K + j];
            }
            C[i * K + j] = sum;      
        }
    }
}

int main() {
    int M = 4, N = 4, K = 4;
    for (int i = 0; i < 4 * 4; i++) {
        matrix[i] = i + 1;  // Simple pattern: 1, 2, 3, ...
    }

    int* A = new int[M * N];
    int* B = new int[N * K];
    int* C = new int[M * K];

    cout << "Matrix A: \n";
    print(A, M, N);

    cout << "Matrix B: \n";
    print(B, N, K);

    int* X, * Y, * Z;
    cudaMalloc(&X, M * N * sizeof(int));
    cudaMalloc(&Y, N * K * sizeof(int));
    cudaMalloc(&Z, M * K * sizeof(int));

    cudaMemcpy(X, A, M * N * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(Y, B, N * K * sizeof(int), cudaMemcpyHostToDevice);

    int THREADS = 16;

    int BLOCKS_X = (K + THREADS - 1) / THREADS;
    int BLOCKS_Y = (M + THREADS - 1) / THREADS;

    dim3 threads(THREADS, THREADS);
    dim3 blocks(BLOCKS_X, BLOCKS_Y);

    auto start = high_resolution_clock::now();
    sequentialMultiply(A, B, C, M, N, K);
    auto stop = high_resolution_clock::now();
    auto seq_duration = duration_cast<microseconds>(stop - start);
    print(C, M, K);
    cout << "Sequential Multiplication Time: " << seq_duration.count() << " microseconds" << endl;

    start = high_resolution_clock::now();
    multiply<<<blocks, threads>>>(X, Y, Z, M, N, K);
    cudaDeviceSynchronize();
    cudaMemcpy(C, Z, M * K * sizeof(int), cudaMemcpyDeviceToHost);
    stop = high_resolution_clock::now();
    auto par_duration = duration_cast<microseconds>(stop - start);
    print(C, M, K);
    cout << "Parallel Multiplication Time: " << par_duration.count() << " microseconds" << endl;

    delete[] A;
    delete[] B;
    delete[] C;

    cudaFree(X);
    cudaFree(Y);
    cudaFree(Z);

    return 0;
}