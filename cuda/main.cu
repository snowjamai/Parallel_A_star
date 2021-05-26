#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cuda_runtime.h>

#include "Route.cuh"

using namespace std;

typedef struct Node {
    int r_len = 0;
    int dest[10];
    float len[10];
} Node;

Node road[10000000];
float lat[10000000];
float lon[10000000];



vector<double> arr;
vector<float> tmp;


__device__ Node *gpu_road;
__device__ int *start_node, *end_node, *start_len, *end_len;
__device__ float *gpu_lat, *gpu_lon;

__global__ void Print(int *a, int *node){
    for(int i = 0; i < *a; ++i)
        printf("***%d\n", node[i]);
}

void GetTmp(string str) {
    string s;

    for (int i = 0; i < str.size(); ++i) {
        if (str[i] != ',')
            s.push_back(str[i]);
        else {
            tmp.push_back(stof(s));
            s.clear();
        }
    }
    tmp.push_back(stof(s));
}

int main(void)
{
    ifstream node, edge;

    string filename("result_noded.csv");

    node.open("result_noded.csv", ios::in);

    vector<string> s;
    if (node.is_open())
    {
        string str;
        getline(node, str);

        int i = 0;
        while (!node.eof())
        {
            printf("%d\n", i++);
            string delim = ",";

            std::getline(node, str);
            if (str == "")
                break;
            GetTmp(str);

            lat[(int)tmp[1]] = tmp[6];
            lon[(int)tmp[1]] = tmp[7];

            if ((int)tmp[4]!= 0) {
                road[(int)tmp[1]].dest[road[(int)tmp[1]].r_len] = (int)tmp[2];
                road[(int)tmp[1]].len[road[(int)tmp[1]].r_len++] = tmp[3];
            }
            if ((int)tmp[5] != 0) {
                road[(int)tmp[2]].dest[road[(int)tmp[2]].r_len] = (int)tmp[1];
                road[(int)tmp[2]].len[road[(int)tmp[2]].r_len++] = tmp[3];
            }
            tmp.clear();
        }
        edge.close();
    }

    cudaMalloc(&gpu_road, 10000000 * sizeof(Node));
    cudaMemcpy(gpu_road, road, 10000000 * sizeof(Node), cudaMemcpyHostToDevice);

    cudaMalloc(&gpu_lat, 10000000 * sizeof(float));
    cudaMemcpy(gpu_lat, lat, 10000000 * sizeof(float), cudaMemcpyHostToDevice);

    cudaMalloc(&gpu_lon, 10000000 * sizeof(float));
    cudaMemcpy(gpu_lon, lon, 10000000 * sizeof(float), cudaMemcpyHostToDevice);

    cudaMalloc(&start_len, sizeof(int));
    cudaMalloc(&start_node, sizeof(int) * 10);
    cudaMalloc(&end_len, sizeof(int));
    cudaMalloc(&end_node, sizeof(int) * 10);


    FindStart<<<1,1>>>(gpu_lat,gpu_lon, 126.972778,37.556328, start_node, start_len);
    FindEnd<<<1,1>>>(gpu_lat,gpu_lon, 129.042049,35.115294, end_node, end_len);
    cudaDeviceSynchronize();




    Print<<<1,1>>>(start_len, start_node);
    Print<<<1,1>>>(end_len, end_node);
    cudaDeviceSynchronize();

    return 0;
}
