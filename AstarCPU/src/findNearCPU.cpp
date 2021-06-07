//
// Created by Taesan on 2021/05/27
//
#include <iostream>

#include "findNearCPU.h"
#include "osmLoadCPU.h"

float epsilon = 0.001;

void FindStartCPU(float *cpu_lat, float *cpu_lon, float st_lat, float st_lon, int *start, int *start_len){
    for (int i = 0; i < TOTAL_NODE_NUM; i++){
        if(cpu_lat[i] >= st_lat - epsilon && cpu_lat[i] < st_lat + epsilon && cpu_lon[i] >= st_lon - epsilon && cpu_lon[i] < st_lon + epsilon) {
            start[(*start_len)++] = i;
            if (*start_len >= 20)
                break;
        }
    }
    printf("START_NODE_NUM[%d]\n", *start_len);
    
    return;
}

void FindEndCPU(float *cpu_lat, float *cpu_lon, float g_lat, float g_lon, int *end, int *end_len){
    for (int i = 0; i < TOTAL_NODE_NUM; i++){
        if(cpu_lat[i] >= g_lat - epsilon && cpu_lat[i] < g_lat + epsilon && cpu_lon[i] >= g_lon - epsilon && cpu_lon[i] < g_lon + epsilon) {
            end[(*end_len)++] = i;
            if (*end_len >= 20)
                break;
        }
    }
    printf("END_NODE_NUM[%d]\n", *end_len);
    
    return;
}