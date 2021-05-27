//
// Created by Taesan on 2021/05/27
//

#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

#include "AstarCPU.h"
#include "dataTypeCPU.h"
#include "osmLoadCPU.h"

using namespace std;

Node* closed_list = new Node [TOTAL_NODE_NUM];

float heuristic(float query_lat, float query_lon, float goal_lat, float goal_lon) {
    // use haversine distance    
    
    // distance between latitudes and longitudes
    float lat_dist = (goal_lat - query_lat) * M_PI / 180.0;
    float lon_dist = (goal_lon - query_lon) * M_PI / 180.0;

    // convert to radians
    query_lat = (query_lat) * M_PI / 180.0;
    goal_lat = (goal_lat) * M_PI / 180.0;

    // apply formular
    float a = pow(sin(lat_dist / 2), 2) + 
              pow(sin(lon_dist / 2), 2) * cos(query_lat) * cos(goal_lat);
    float rad = 6371;
    float c = 2 * asin(sqrt(a));

    return rad * c;
}

int astarCPU(int *st_node, int *goal_node, int st_num, int goal_num, float goal_lat, float goal_lon){
    auto cmp = [](Node *small, Node *large) { return small->f > large->f; };
    std::priority_queue<Node*, std::vector<Node*>, decltype(cmp)> open_list(cmp);
    // Node* closed_list = new Node [TOTAL_NODE_NUM];

    
    for (int i = 0; i < st_num; i++) {
        road[st_node[i]].g = 0;
        road[st_node[i]].f = heuristic(lat[st_node[i]], lon[st_node[i]], goal_lat, goal_lon);
        open_list.push(&road[st_node[i]]);
    }

    int cnt = 0;
    while (!open_list.empty()) {
        cnt++;

        Node* q = open_list.top();
        open_list.pop();

        for (int i = 0; i < goal_num; i++) {
            if (q->node_id == goal_node[i]){
                printf("goal node[%d]\n", q->node_id);
                printf("COUNT[%d]\n", cnt);
                return q->node_id;
            }
        }
        // if (q->node_id == goal_node[0]) {
        //     printf("goal node[%d]\n", q->node_id);
        //     printf("COUNT[%d]\n", cnt);
        //     return q->node_id;
        // }
        
        Node** ex_nodes = new Node* [q->r_len];
        for (int i = 0; i < q->r_len; i++) {
            ex_nodes[i] = &road[q->dest[i]];
            ex_nodes[i]->g = q->g + q->len[i];
            ex_nodes[i]->f = ex_nodes[i]->g + heuristic(lat[q->dest[i]], lon[q->dest[i]], goal_lat, goal_lon);
        }

        for (int i = 0; i < q->r_len; i++) {
            if (closed_list[q->dest[i]].node_id == -1 || ex_nodes[i]->f < closed_list[q->dest[i]].f) {
                ex_nodes[i]->prev_node = q;
                open_list.push(ex_nodes[i]);
                closed_list[q->dest[i]] = *ex_nodes[i];
            }
        }
    }
    
    return -1;
}

vector<Node*> generateRoute(int* st_node, int st_num, int goal_id) {
    vector<Node*> Route;
    int node_id = goal_id;

    while (1) {
        Route.push_back(&road[node_id]);
        node_id = road[node_id].prev_node->node_id;

        for (int i = 0; i < st_num; i++) {
            if (node_id == st_node[i]) {
                Route.push_back(&road[node_id]);
                reverse(Route.begin(), Route.end());
                return Route;
            }
        }
    }
}