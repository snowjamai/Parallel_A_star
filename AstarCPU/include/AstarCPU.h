//
// Created by Taesan on 2021/05/26
//

#ifndef ASTAR_CPU_H
#define ASTAR_CPU_H

float heuristic(float query_lat, float query_lon, float goal_lat, float goal_lon);

void astarCPU(int *st_node, int *goal_node, int st_num, int goal_num, float goal_lat, float goal_lon);

#endif // ASTAR_CPU_H