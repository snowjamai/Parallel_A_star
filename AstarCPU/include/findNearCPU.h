//
// Created by Taesan on 2021/05/26
//
#ifndef FIND_NEAR_CPU
#define FIND_NEAR_CPU

#endif // FIND_NEAR_CPU

#include <iostream>

#include "osmLoadCPU.h"

float epsilon = 0.001;

void FindStartCPU(float *cpu_lat, float *cpu_lon, float lat, float lon, int *start, int *start_len){
    // printf("%d\n", *start_len);
    for (int i = 0; i < TOTAL_NODE_NUM; i++){
        // printf("%d\n", i);
        if(cpu_lat[i] >= lat - epsilon && cpu_lat[i] < lat + epsilon && cpu_lon[i] >= lon - epsilon && cpu_lon[i] < lon + epsilon) {
            start[(*start_len)++] = i;
            // start[(*start_len)] = i;
            // printf("%d %d\n", start[(*start_len)], (*start_len));
            // (*start_len)++;
        }
    }
    printf("START_NODE_NUM[%d]\n", *start_len);
    
    return;
}

void FindEndCPU(float *cpu_lat, float *cpu_lon, float lat, float lon, int *end, int *end_len){
    // printf("%d\n", *end_len);
    for (int i = 0; i < TOTAL_NODE_NUM; i++){
        if(cpu_lat[i] >= lat - epsilon && cpu_lat[i] < lat + epsilon && cpu_lon[i] >= lon - epsilon && cpu_lon[i] < lon + epsilon)
            end[(*end_len)++] = i;
    }
    printf("END_NODE_NUM[%d]\n", *end_len);
    
    return;
}