#include <iostream>

#include "myKernel.h"

#define SIZE 1024

#define checkCudaErrors(val) check( (val), #val, __FILE__,__LINE__)

template <typename T>
void check(T err, const char* const func, const char* const file, const int line) {
    if (err != cudaSuccess) {
        std::cerr << "CUDA error at: " << file << ":" << line << std::endl;
        std::cerr << cudaGetErrorString(err) << " " << func << std::endl;
        exit(EXIT_FAILURE);
    }
}

int main() {
    int *a, *b, *c;       // host pointer
    int *d_a, *d_b, *d_c; // device pointer

    a = new int[SIZE];
    b = new int[SIZE];
    c = new int[SIZE];

    checkCudaErrors(cudaMalloc(&d_a, SIZE * sizeof(int)));
    checkCudaErrors(cudaMalloc(&d_b, SIZE * sizeof(int)));
    checkCudaErrors(cudaMalloc(&d_c, SIZE * sizeof(int)));

    for (int i = 0; i < SIZE; i++) {
        a[i] = i;
        b[i] = i;
        c[i] = 0;
    }

    checkCudaErrors(cudaMemcpy(d_a, a, SIZE * sizeof(int), cudaMemcpyHostToDevice));
    checkCudaErrors(cudaMemcpy(d_b, b, SIZE * sizeof(int), cudaMemcpyHostToDevice));
    checkCudaErrors(cudaMemcpy(d_c, c, SIZE * sizeof(int), cudaMemcpyHostToDevice));

    const dim3 blockSize(SIZE, 1, 1);
    const dim3 gridSize(1, 1, 1);
    // invoking the Kernel (kernel is invoked asynchrounsly)
    myGPUvectorAdd(gridSize, blockSize, d_a, d_b, d_c, SIZE);
    // cudaMemcpy() has an inherent blocking device synchronization built into them. 
    //checkCudaErrors(cudaDeviceSynchronize());
    checkCudaErrors(cudaMemcpy(c, d_c, SIZE * sizeof(int), cudaMemcpyDeviceToHost));
    
    for (int i = 0; i < 10; i++) {
        printf("c[%d] = %d\n", i, c[i]);
    }

    delete[] a;
    delete[] b;
    delete[] c;

    checkCudaErrors(cudaFree(d_a));
    checkCudaErrors(cudaFree(d_b));
    checkCudaErrors(cudaFree(d_c));

    return EXIT_SUCCESS;
}