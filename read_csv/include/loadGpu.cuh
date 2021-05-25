#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "dataType.cuh"
using namespace std;


vector<float> tmp;
Node road[10000000];
float lan[10000000];
float lot[10000000];



//string -> float
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
//load mapdata from csv & link node
void LoadMap(string csv)
{
    ifstream node, edge;

    string filename(csv);

    node.open(csv, ios::in);

    vector<string> s;
    if (node.is_open())
    {
        string str;
        string delim = ",";
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
}
//load gpu mapdata
__global__ void LoadMapGPU(Node *)
