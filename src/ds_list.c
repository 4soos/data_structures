//
// Created by young on 10/01/2021.
//

#include "common.h"
// 线性表的数组实现

# if(Array == 1)
typedef struct LNode *List;
struct LNode{
    ElementType Data[MAXSIZE];
    int Last;
} ;
struct LNode L;
List PtrL;

List MakeEmpty() {
    List Ptrl;

    Ptrl = (List) malloc(sizeof(struct LNode));
    Ptrl->Last = -1;
    return Ptrl;
}

int Find(ElementType X, List Ptrl) {
    int i = 0;

    while (i <= Ptrl->Last && Ptrl->Data[i] != X) i++;

    if (i > Ptrl->Last) return -1;
    else return i;
}


void Insert(ElementType X, int i, List PtrL) {
    int j;
    if (PtrL->Last == MaxSize - 1) return;
    if (i < 1 || PtrL->Last+2) return;

    for (j = PtrL->Last; j>= i-1; j--)
        PtrL->Data[j+1] = PtrL->Data[j];
    PtrL->Data[i-1] = X;
    PtrL->Last++;

    return;
}


void Delete(int i, List PtrL) {
    int j;
    if (i<1 || i > PtrL->Last+1) return;

    for (j = 1; j <= PtrL->Last; j++)
        PtrL->Data[j-1] = PtrL->Data[j];
    PtrL->Last--;

    return;
}
#else
// 链式存储
typedef struct LNode*  List;
struct LNode {
    ElementType Data;
    List Next;
};
struct Lnode L;
List PtrL;

int Length(List list) {
    List pList = list;
    int counter = 0;
    while (pList) {
        p = pList->Next;
        counter++;
    }
    return counter;
}

// 按位置查找
List FindKth(int K, List PtrL) {
    List p = PtrL;
    int i = 1;
    while ( p != NULL && i < K) {
        p = p->Next;
        i++;
    }
    if (i == K) return p;
    else return NULL;
}

// 按值查找
List Find(ElementType X, List PtrL) {
    List p = PtrL;
    while (p != NULL && p->Data != X) {
        p = p->Next;
    }
    return p;
}

List Insert(ElementType X, int i, List PtrL) {
    List p, s;
    if (i == 1) {
        s = (List) malloc(sizeof(struct LNode));
        s->Data = X;
        s->Next = PtrL
        return s;
    }

    p = FindKth(i-1, PtrL);
    if ( p == NULL) return NULL;
    else {
        s = (List) malloc(sizeof (struct LNode));
        s->Data = X;
        s->Next = p->Next;
        p->Next = s;
        return PtrL;
    }
}

List Delete(int i, List PtrL) {
    List p, s;
    if (i == 1) {
        s = PtrL;
        if (PtrL != NULL) PtrL = PtrL->Next;
        else return NULL;
        free(s);
        return PtrL;
    }
    p = FindKth(i-1, PtrL);

    if (p == NULL) return NULL;
    else if (p->Next == NULL) return NULL;
    else {
        s = p->Next;
        p->Next = s->Next;
        free(s);
        return PtrL;
    }
}


// 广义表
typedef struct GNode* GList;
struct GNode {
    int Tag;
    union {
        ElementType Data;
        GList SubList;
    } URegion;
    GList Next;
};



#endif