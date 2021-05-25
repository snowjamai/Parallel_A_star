#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cuda_runtime.h>

using namespace std;

typedef struct Node {
    int r_len = 0;
    int dest[10];
    float len[10];
} Node;

Node road[10000000];
float lan[10000000];
float lot[10000000];


vector<double> arr;
vector<float> tmp;

__global__ void Print(Node *a){
    printf("%d\n", a[999].dest[0]);
}

__device__ Node *gpu_road;
__device__ int start_node, end_node;

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

            lan[(int)tmp[1]] = tmp[6];
            lot[(int)tmp[1]] = tmp[7];

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

    Print<<<1,1>>>(gpu_road);
    cudaDeviceSynchronize();

    return 0;
}
