//
// Created by young on 10/01/2021.
//

#ifndef DATA_STRUCTURE_DS_QUEUE_H
#define DATA_STRUCTURE_DS_QUEUE_H

#include "common.h"

// defined for queue: Array implementation
#if (Array == 1)

struct QNode {
    ElementType Data[MaxSize];
    int rear;
    int front;
};

typedef struct QNode *Queue;

#else /* END of Array implementaion */

// defined for queue: linked implementation

struct Node {
    ElementType Data;
    struct Node *Next;
};

struct QNode {
    int MaxSize;
    struct Node * rear;
    struct Node * front;
};

typedef struct Node *PtrToNode;

typedef PtrToNode Position;

typedef struct QNode *Queue;

Queue PtrQ;

#endif /* END of linked implementation */

#endif //DATA_STRUCTURE_DS_QUEUE_H
