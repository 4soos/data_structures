//
// Created by young on 10/01/2021.
//

#include "ds_queue.h"

#if (Array == 1) // array implementation

void AddQ(Queue PtrQ, ElementType item) {
    if ((PtrQ->read+1) % MaxSize == PtrQ->front) return;

    PtrQ->rear = (PtrQ->rear+1) % MaxSize;
    PtrQ->Data[PtrQ->rear] = item;
}

ElementType DeleteQ(Queue PtrQ) {
    if (PtrQ->front == PtrQ->rear) return ERROR;
    else {
        PtrQ->front = (PtrQ->front+1) % MaxSize;
        return PtrQ->Data[PtrQ->front];
    }
}

#else // linked implementation

ElementType DeleteQ(Queue Q) {
    Position FrontCell;
    ElementType FrontElem;

    if (IsEmpty(Q)) {
        printf("队列空");
        return ERROR;
    } else {
        FrontCell = Q->Front;
        if (Q->Front == Q->Rear) /* 若队列只有一个元素 */
            Q->Front = Q->Rear = NULL; /* 删除后队列置为空 */
        else
            Q->Front = Q->Front->Next;
        FrontElem = FrontCell->Data;

        free(FrontCell);  /* 释放被删除结点空间  */
        return FrontElem;
    }
}

bool AddQ( Queue Q, ElementType X )
{
    if ( IsFull(Q) ) {
        printf("队列满");
        return false;
    }
    else {
        Q->Rear = (Q->Rear+1)%Q->MaxSize;
        Q->Data[Q->Rear] = X;
        return true;
    }
}


bool is_full(Queue Q) {
    return ((Q->rear + 1) % )
}

bool is_empty(Queu Q) {
    return (Q->Front == NULL);
}

#endif



