//
// Created by Taesan on 2021/05/25
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>

#include "osmLoadCPU.h"
#include "dataTypeCPU.h"
#include "findNearCPU.h"
#include "AstarCPU.h"

using namespace std;

int main(void)
{
   string osm_csv = "../../osm_data/result_node.csv";
   LoadMapCPU(osm_csv);

   // float st_lat(37.566572), st_lon(126.978411);     // Seoul cityhall
   // float goal_lat(35.115110), goal_lon(129.041224); // Busan station
   float st_lat(37.556328), st_lon(126.972778);
   float goal_lat(35.115294), goal_lon(129.042049);
   int st_node[10], goal_node[10];
   int st_num(0), goal_num(0);

   FindStartCPU(lat, lon, st_lat, st_lon, st_node, &st_num);
   FindEndCPU(lat, lon, goal_lat, goal_lon, goal_node, &goal_num);
   
   printf("start\n");
   for (int i = 0; i < st_num; i++)
      printf("%d ", st_node[i]);
   printf("\n");

   printf("goal\n");
   for (int i = 0; i < goal_num; i++)
      printf("%d ", goal_node[i]);
   printf("\n");

   std::chrono::system_clock::time_point gpu_t1, gpu_t2;
   gpu_t1 = std::chrono::system_clock::now();			
		
   int goal_id = astarCPU(st_node, goal_node, st_num, goal_num, goal_lat, goal_lon);

   gpu_t2 = std::chrono::system_clock::now();
   
   if (goal_id == -1) {
      printf("[Error] Couldn't find any route.\n");
   }

   vector<Node*> totalRoute = generateRoute(st_node, st_num, goal_id);
   cout << 1e-9 * std::chrono::duration_cast<std::chrono::nanoseconds>(gpu_t2 - gpu_t1).count() << std::endl;

   cout << "start node[" << totalRoute[0]->node_id << "]" << endl;
   cout << "Route size[" << totalRoute.size() << "]" << endl;
   return 0;
}