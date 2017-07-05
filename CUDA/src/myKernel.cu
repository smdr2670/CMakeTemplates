#include "myKernel.h"

// running parallel for each thread
__global__ 
void vectorAdd(int* a, int* b, int* c, int n){
    
    int i = threadIdx.x;
    if (i < n){
        c[i] = a[i] + b[i];
    }
}

// Wrapper function so the .cpp file has not to invoke the kernel directly
void myGPUvectorAdd(const dim3 gridSize, const dim3 blockSize, int* a, int* b, int* c, int n) {
    vectorAdd <<< gridSize, blockSize  >>> (a, b, c, n);
}

