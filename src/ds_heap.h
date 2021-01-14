//
// Created by young on 10/01/2021.
//

#ifndef DATA_STRUCTURE_DS_PQUEUE_H
#define DATA_STRUCTURE_DS_PQUEUE_H

#include "common.h"

typedef struct HeapStruct *MaxHeap;

struct HeapStruct {
    ElementType *Elements;
    int Size;
    int Capacity;
};

/**
 * 优先队列的实现
 * 1. 数组
 * 2. 链表
 * 3. 有序数组
 * 4. 有序链表
 * 5. 完全二叉树
 */
MaxHeap create(int MaxSize);

bool is_full(MaxHeap H);

void insert(MaxHeap H, ELementType item);

bool is_empty(MaxHeap H);

ELementType delete_max(MaxHeap H);

#endif //DATA_STRUCTURE_DS_PQUEUE_H
