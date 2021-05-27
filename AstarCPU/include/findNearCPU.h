//
// Created by Taesan on 2021/05/26
//
#ifndef FIND_NEAR_CPU_H
#define FIND_NEAR_CPU_H

#include <iostream>

#include "osmLoadCPU.h"

extern float epsilon;

void FindStartCPU(float *cpu_lat, float *cpu_lon, float lat, float lon, int *start, int *start_len);

void FindEndCPU(float *cpu_lat, float *cpu_lon, float lat, float lon, int *end, int *end_len);

#endif // FIND_NEAR_CPU_H