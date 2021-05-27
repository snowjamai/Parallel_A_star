//
// Created by Taesan on 2021/05/27
//
#include <iostream>

#include "findNearCPU.h"
#include "osmLoadCPU.h"

float epsilon = 0.0005;

void FindStartCPU(float *cpu_lat, float *cpu_lon, float lat, float lon, int *start, int *start_len){
    for (int i = 0; i < TOTAL_NODE_NUM; i++){
        if(cpu_lat[i] >= lat - epsilon && cpu_lat[i] < lat + epsilon && cpu_lon[i] >= lon - epsilon && cpu_lon[i] < lon + epsilon) {
            start[(*start_len)++] = i;
        }
    }
    printf("START_NODE_NUM[%d]\n", *start_len);
    
    return;
}

void FindEndCPU(float *cpu_lat, float *cpu_lon, float lat, float lon, int *end, int *end_len){
    for (int i = 0; i < TOTAL_NODE_NUM; i++){
        if(cpu_lat[i] >= lat - epsilon && cpu_lat[i] < lat + epsilon && cpu_lon[i] >= lon - epsilon && cpu_lon[i] < lon + epsilon)
            end[(*end_len)++] = i;
    }
    printf("END_NODE_NUM[%d]\n", *end_len);
    
    return;
}