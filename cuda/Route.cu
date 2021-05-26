//
// Created by snowjam02 on 5/25/21.
//
#include <iostream>
#include "Route.cuh"
__device__ float epsilon = 0.001;

__global__ void FindStart(float *gpu_lat,float *gpu_lon, float lat, float lon, int *start, int *start_len){
    printf("%d\n", *start_len);
    for(int i = 1; i < 10000000; ++i) {
        if (gpu_lat[i] >= lat - epsilon && gpu_lat[i] < lat + epsilon && gpu_lon[i] >= lon - epsilon && gpu_lon[i] < lon + epsilon)
            start[(*start_len)++] = i;
    }
    printf("%d\n", *start_len);
    return;
}
__global__ void FindEnd(float *gpu_lat, float *gpu_lon, float lat, float lon, int *end, int *end_len) {
    for(int i = 1; i < 10000000; ++i)
        if(gpu_lat[i] >= lat - epsilon && gpu_lat[i] < lat + epsilon && gpu_lon[i] >= lon - epsilon && gpu_lon[i] < lon + epsilon)
            end[(*end_len)++] = i;
    printf("%d\n", *end_len);
    return;
}