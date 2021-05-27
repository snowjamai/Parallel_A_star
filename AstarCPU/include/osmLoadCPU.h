//
// Created by Taesan on 2021/05/25
//

#ifndef OSM_LOAD_CPU_H
#define OSM_LOAD_CPU_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "dataTypeCPU.h"

#define TOTAL_NODE_NUM 10000000
using namespace std;

extern vector<float> tmp;
extern Node road[TOTAL_NODE_NUM];
extern float lat[TOTAL_NODE_NUM];
extern float lon[TOTAL_NODE_NUM];

// string -> float
void GetTmp(string str);

// load mapdata from csv & link node
void LoadMapCPU(string csv);

#endif // OSM_LOAD_CPU_H