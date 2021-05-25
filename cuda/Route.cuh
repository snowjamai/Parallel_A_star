//
// Created by snowjam02 on 5/25/21.
//

#ifndef PA_ROUTE_CUH
#define PA_ROUTE_CUH

#endif //PA_ROUTE_CUH

__global__ void FindStart(float *gpu_lat,float *gpu_lon, float lat, float lon, int *start, int *start_len);
__global__ void FindEnd(float *gpu_lat, float *gpu_lon, float lat, float lon, int *end, int *end_len);