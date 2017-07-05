#ifndef MYKERNEL_H
#define MYKERNEL_H

#include <cuda.h>
#include <cuda_runtime.h>

__global__ void vectorAdd(int* a, int* b, int* c, int n);

void myGPUvectorAdd(const dim3 blockSize, const dim3 gridSize, int* a, int* b, int* c, int n);

#endif 