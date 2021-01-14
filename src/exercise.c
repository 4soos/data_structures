//
// Created by young on 10/01/2021.
//

#include "common.h"


// 同一个数组实现2个堆栈: 从数组两端向中间生成
struct DStack {
    ElementType Data[MaxSize];
    int Top1;
    int Top2;
} S;

S.Top1 = -1;
S.Top2 = MaxSize;

void Push(struct DStack *PtrS, ElementType item, int Tag) {
    if ((PtrS->Top2 - PtrS->Top1) == 1) return;
    if (Tag == 1) PtrS->Data[++(PtrS->Top1)] = item;
    else PtrS->Data[--(PtrS->Top2)] = item;
}


ElementType Pop(struct DStack *PtrS, int Tag) {
    if (Tag == 1) {
        if (PtrS->Top1 == -1) return NULL;
        else return PtrS->Data[(PtrS->Top1)--];
    } else {
        if (PtrS->Top2 == MaxSize) return NULL;
        else return PtrS->Data[(PtrS->Top2)++];
    }
}

#define MAXN 1000                  /* 集合最大元素个数 */
typedef int ElementType;           /* 默认元素可以用非负整数表示 */
typedef int SetName;               /* 默认用根结点的下标作为集合名称 */
typedef ElementType SetType[MAXN]; /* 假设集合元素下标从0开始 */

void Union( SetType S, SetName Root1, SetName Root2 )
{ /* 这里默认Root1和Root2是不同集合的根结点 */
    /* 保证小集合并入大集合 */
    if ( S[Root2] < S[Root1] ) { /* 如果集合2比较大 */
        S[Root2] += S[Root1];     /* 集合1并入集合2  */
        S[Root1] = Root2;
    }
    else {                         /* 如果集合1比较大 */
        S[Root1] += S[Root2];     /* 集合2并入集合1  */
        S[Root2] = Root1;
    }
}

SetName Find( SetType S, ElementType X )
{ /* 默认集合元素全部初始化为-1 */
    if ( S[X] < 0 ) /* 找到集合的根 */
        return X;
    else
        return S[X] = Find( S, S[X] ); /* 路径压缩 */
}









