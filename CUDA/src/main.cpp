#include <stdio.h>

#include <cuda.h>
#include <cuda_runtime.h>

#include "myKernel.h"

#define SIZE 1024

int main() {
    int *a, *b, *c;       // host pointer
    int *d_a, *d_b, *d_c; // device pointer

    a = (int *)malloc(SIZE * sizeof(int));
    b = (int *)malloc(SIZE * sizeof(int));
    c = (int *)malloc(SIZE * sizeof(int));

    cudaMalloc(&d_a, SIZE * sizeof(int));
    cudaMalloc(&d_b, SIZE * sizeof(int));
    cudaMalloc(&d_c, SIZE * sizeof(int));

    for (int i = 0; i < SIZE; i++) {
        a[i] = i;
        b[i] = i;
        c[i] = 0;
    }

    cudaMemcpy(d_a, a, SIZE * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_b, b, SIZE * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_c, c, SIZE * sizeof(int), cudaMemcpyHostToDevice);

    //vectorAdd <<< 1, SIZE >>> (d_a, d_b, d_c, SIZE);
    vectorWrap(d_a, d_b, d_c, SIZE);

    cudaMemcpy(c, d_c, SIZE * sizeof(int), cudaMemcpyDeviceToHost);

    for (int i = 0; i < 10; i++) {
        printf("c[%d] = %d\n", i, c[i]);
    }

    free(a);
    free(b);
    free(c);

    cudaFree(d_a);
    cudaFree(d_b);
    cudaFree(d_c);

    return 0;
}