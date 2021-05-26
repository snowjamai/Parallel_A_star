//
// Created by Taesan on 2021/05/25
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "osmLoadCPU.h"
#include "dataTypeCPU.h"
#include "findNearCPU.h"

using namespace std;

int main(void)
{
   string osm_csv = "../osm_data/result_node.csv";
   LoadMapCPU(osm_csv);


   double st_lon(37.566572), st_lat(126.978411);     // Seoul cityhall
   double goal_lon(35.115110), goal_lat(129.041224); // Busan station
   
   int start_node[10], goal_node[10];
   int start_num(0), goal_num(0);

   FindStartCPU(lat, lon, st_lat, st_lon, start_node, &start_num);
   FindEndCPU(lat, lon, goal_lat, goal_lon, goal_node, &goal_num);
   // FindStartCPU(lat, lon, 126.972778, 37.556328, start_node, &start_num);
   // FindEndCPU(lat, lon, 129.042049, 35.115294, goal_node, &goal_num);
   
   // for (int i = 0; i < start_num; i++)
   //    printf("%d\n", start_node[i]);
   
   // for (int i = 0; i < goal_num; i++)
   //    printf("%d\n", goal_node[i]);

   astarCPU();
   return 0;
}