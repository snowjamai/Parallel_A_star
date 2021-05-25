#include "../include/loadGpu.cuh"

int main(void)
{
    string mapcsv = "../data/result_noded.csv";
    LoadMap(mapcsv);
    return 0;
}