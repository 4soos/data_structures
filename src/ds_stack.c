//
// Created by young on 10/01/2021.
//

#include "common.h"

#if (Array == 1)
typedef struct SNode* Stack;
struct SNode {
    ELementType Data[MaxSize];
    int Top;
};

void Push(Stack PtrS, ElementType item) {
    if (PtrS->Top == MaxSize - 1) return;
    else PtrS->Data[++(PtrS->Top)] = item;
}

ElementType Pop(Stack PtrS) {
    if (PtrS->Top == -1) return ERROR;
    else return (PtrS->Data[(PtrS->Top)--]);
}

#else

typedef struct SNode* Stack;
struct SNode {
    ElementType Data;
    struct SNode * Next;
};

Stack create() {
    Stack stack;
    stack = (Stack) malloc(sizeof(struct SNode));
    stack->Next = NULL;
    return stack;
}

int is_empty(Stack S) {
    return (S->Next == NULL);
}

void push(ElementType item, Stack S) {
    struct SNode* tmpCell;
    tmpCell = (struct SNode*) malloc(sizeof(struct SNode));
    tmpCell->Element = item;
    tmpCell->Next = S->Next;
    S->Next = tmpCell;
}

ElementType Pop(Stack S) {
    struct SNode *firstCell;
    ElementType topElem;
    if (is_empty(S)) return NULL;
    else {
        firstCell = S->Next;
        S->Next = firstCell->Next;
        topElem = firstCell->Data;
        free(firstCell);
        return topElem;
    }
}







#endif