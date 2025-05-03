
// Basic CUDA implementation for parallel reduction operations
#include <stdio.h>
#include <limits.h>

#define BLOCK_SIZE 256

// Kernel for finding minimum value
__global__ void reduceMin(int* input, int* output, int size) {
    __shared__ int sdata[BLOCK_SIZE];
    unsigned int tid = threadIdx.x;
    unsigned int i = blockIdx.x * blockDim.x + threadIdx.x;

    // Load data into shared memory
    if (i < size) {
        sdata[tid] = input[i];
    } else {
        sdata[tid] = INT_MAX;  // Identity for min
    }

    __syncthreads();

    // Reduction in shared memory
    for (unsigned int stride = blockDim.x / 2; stride > 0; stride >>= 1) {
        if (tid < stride) {
            sdata[tid] = min(sdata[tid], sdata[tid + stride]);
        }
        __syncthreads();
    }

    // Write result for this block
    if (tid == 0) {
        output[blockIdx.x] = sdata[0];
    }
}

// Kernel for finding maximum value
__global__ void reduceMax(int* input, int* output, int size) {
    __shared__ int sdata[BLOCK_SIZE];
    unsigned int tid = threadIdx.x;
    unsigned int i = blockIdx.x * blockDim.x + threadIdx.x;

    // Load data into shared memory
    if (i < size) {
        sdata[tid] = input[i];
    } else {
        sdata[tid] = INT_MIN;  // Identity for max
    }

    __syncthreads();

    // Reduction in shared memory
    for (unsigned int stride = blockDim.x / 2; stride > 0; stride >>= 1) {
        if (tid < stride) {
            sdata[tid] = max(sdata[tid], sdata[tid + stride]);
        }
        __syncthreads();
    }

    // Write result for this block
    if (tid == 0) {
        output[blockIdx.x] = sdata[0];
    }
}

// Kernel for calculating sum
__global__ void reduceSum(int* input, int* output, int size) {
    __shared__ int sdata[BLOCK_SIZE];
    unsigned int tid = threadIdx.x;
    unsigned int i = blockIdx.x * blockDim.x + threadIdx.x;

    // Load data into shared memory
    if (i < size) {
        sdata[tid] = input[i];
    } else {
        sdata[tid] = 0;  // Identity for sum
    }

    __syncthreads();

    // Reduction in shared memory
    for (unsigned int stride = blockDim.x / 2; stride > 0; stride >>= 1) {
        if (tid < stride) {
            sdata[tid] += sdata[tid + stride];
        }
        __syncthreads();
    }

    // Write result for this block
    if (tid == 0) {
        output[blockIdx.x] = sdata[0];
    }
}

// Kernel for calculating average
__global__ void reduceAverage(int* input, float* output, int size) {
    __shared__ float sdata[BLOCK_SIZE];
    unsigned int tid = threadIdx.x;
    unsigned int i = blockIdx.x * blockDim.x + threadIdx.x;

    // Load data into shared memory
    if (i < size) {
        sdata[tid] = static_cast<float>(input[i]);
    } else {
        sdata[tid] = 0.0f;
    }

    __syncthreads();

    // Reduction in shared memory (sum)
    for (unsigned int stride = blockDim.x / 2; stride > 0; stride >>= 1) {
        if (tid < stride) {
            sdata[tid] += sdata[tid + stride];
        }
        __syncthreads();
    }

    // Calculate average and write result
    if (tid == 0) {
        output[blockIdx.x] = sdata[0] / static_cast<float>(size);
    }
}

int main() {
    // Input array setup
    const int array_size = 256;
    int h_input[array_size];

    // Initialize array with values 1 to array_size
    for (int i = 0; i < array_size; ++i) {
        h_input[i] = i + 1;
    }

    // Allocate device memory
    int *d_input, *d_output;
    float *d_output_avg;
    cudaMalloc((void**)&d_input, sizeof(int) * array_size);
    cudaMalloc((void**)&d_output, sizeof(int));
    cudaMalloc((void**)&d_output_avg, sizeof(float));

    // Copy input to device
    cudaMemcpy(d_input, h_input, sizeof(int) * array_size, cudaMemcpyHostToDevice);

    // Set up grid and blocks
    int threads_per_block = BLOCK_SIZE;
    int blocks_per_grid = 1;  // Simplified to one block for basic example

    // Launch kernels
    reduceMin<<<blocks_per_grid, threads_per_block>>>(d_input, d_output, array_size);
    int min_result;
    cudaMemcpy(&min_result, d_output, sizeof(int), cudaMemcpyDeviceToHost);

    reduceMax<<<blocks_per_grid, threads_per_block>>>(d_input, d_output, array_size);
    int max_result;
    cudaMemcpy(&max_result, d_output, sizeof(int), cudaMemcpyDeviceToHost);

    reduceSum<<<blocks_per_grid, threads_per_block>>>(d_input, d_output, array_size);
    int sum_result;
    cudaMemcpy(&sum_result, d_output, sizeof(int), cudaMemcpyDeviceToHost);

    reduceAverage<<<blocks_per_grid, threads_per_block>>>(d_input, d_output_avg, array_size);
    float avg_result;
    cudaMemcpy(&avg_result, d_output_avg, sizeof(float), cudaMemcpyDeviceToHost);

    // Print results
    printf("Minimum value: %d\n", min_result);
    printf("Maximum value: %d\n", max_result);
    printf("Sum: %d\n", sum_result);
    printf("Average: %.2f\n", avg_result);

    // Free device memory
    cudaFree(d_input);
    cudaFree(d_output);
    cudaFree(d_output_avg);

    return 0;
}