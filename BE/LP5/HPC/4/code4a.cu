%%cu
#include <iostream>    
#include <vector>      
#include <chrono>     // for time measuring 
#include <cuda.h> 

using namespace std;
using namespace std::chrono;

__global__ void add(int* A, int* B, int* C, int size) {
    int tid = blockIdx.x * blockDim.x + threadIdx.x;
    if (tid < size) {
        C[tid] = A[tid] + B[tid];
    }
}

// Sequential CPU implementation of vector addition
void sequentialAddition(int* A, int* B, int* C, int size) {
    for (int i = 0; i < size; i++) {
        C[i] = A[i] + B[i];
        cout << C[i] << " " ;
    }
    cout <<endl ; 
}

int main() {
    int N;           
    cout << "Enter the size of the vectors: ";
    cin >> N;

    int* A, * B, * C;
    
    size_t vectorBytes = N * sizeof(int);

    A = new int[N];
    B = new int[N];
    C = new int[N];

    // inserting default value here you can take proper custom value 
    for (int i = 0; i < N; i++) {
        A[i] = i + 1;
        B[i] = i + 2 ; 
    }

    // Print the input vectors
    for (int i = 0; i < N; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < N; i++) {
        cout << B[i] << " ";
    }
    cout << endl;

    int* X, * Y, * Z;

    cudaMalloc(&X, vectorBytes);
    cudaMalloc(&Y, vectorBytes);
    cudaMalloc(&Z, vectorBytes);

    cudaMemcpy(X, A, vectorBytes, cudaMemcpyHostToDevice);
    cudaMemcpy(Y, B, vectorBytes, cudaMemcpyHostToDevice);

    int threadsPerBlock = 256;
    int blocksPerGrid = (N + threadsPerBlock - 1) / threadsPerBlock;

    auto start = high_resolution_clock::now();
    sequentialAddition(A, B, C, N);
    auto stop = high_resolution_clock::now();
    auto seq_duration = duration_cast<microseconds>(stop - start);
    cout << "Sequential Addition Time: " << seq_duration.count() << " microseconds" << endl;

    start = high_resolution_clock::now();
    add<<<blocksPerGrid, threadsPerBlock>>>(X, Y, Z, N);
    cudaMemcpy(C, Z, vectorBytes, cudaMemcpyDeviceToHost);
    for (int i = 0 ; i <  N ; i ++){
        cout << C[i] << " " ; 
    }
    cout << endl ; 
    stop = high_resolution_clock::now();
    auto par_duration = duration_cast<microseconds>(stop - start);
    cout << "Parallel Addition Time: " << par_duration.count() << " microseconds" << endl;

    delete[] A;
    delete[] B;
    delete[] C;

    cudaFree(X);
    cudaFree(Y);
    cudaFree(Z);

    return 0;
}