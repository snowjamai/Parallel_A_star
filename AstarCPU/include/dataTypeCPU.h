//
// Created by Taesan on 2021/05/25
//
#ifndef DATA_TYPE_CPU_H
#define DATA_TYPE_CPU_H

typedef struct Node {
   int node_id = -1;
   Node *prev_node;
   int r_len = 0;
   int dest[10];
   float len[10];
   
   float f = 0;
   float g = 0;

} Node;

#endif // DATA_TYPE_CPU_H