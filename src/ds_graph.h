//
// Created by young on 13/01/2021.
//

#ifndef DATA_STRUCTURE_DS_GRAPH_H
#define DATA_STRUCTURE_DS_GRAPH_H

#define MaxVertxNum 100
#define INFINITY 65535

#define Array 0

typedef int Vertex;
typedef int WeightType;
typedef char DataType;


#if (Array == 1)
/* 边的定义 */
typedef struct ENode *PtrToENode
struct ENode{
    Vertex V1, V2;
    WeightType Weight;
};
typedef PtrToENode Edge;

/* 图结点的定义 */
typedef struct GNode *PtrToGNode;
struct GNode{
    int Nv; /* 顶点数 */
    int Ne; /* 边数 */
    WeightType G[MaxVertxNum][MaxVertxNum]; /* 邻接矩阵 */
    DataType Data[MaxVertxNum];             /* 存顶点的数据 */
    /* 在顶点无数据时, data[]可以不出现 */
};
typedef PtrToGNode MGraph;

MGraph CreateGraph(int VertexNum);

void InsertEdge(MGraph mGraph, Edge E);

MGraph BuildGraph();

#else
/* 边的定义 */
typedef struct ENode *PtrToENode;
struct ENode {
    Vertex V1, V2;      /* 有向边<V1, V2> */
    WeightType Weight;  /* 权重 */
};
typedef PtrToENode Edge;

/* 邻接点的定义 */
typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode {
    Vertex AdjV;        /* 邻接点下标 */
    WeightType Weight;  /* 边权重 */
    PtrToAdjVNode Next;    /* 指向下一个邻接点的指针 */
};

/* 顶点表头结点的定义 */
typedef struct Vnode {
    PtrToAdjVNode FirstEdge;/* 边表头指针 */
    DataType Data;            /* 存顶点的数据 */
    /* 注意：很多情况下，顶点无数据，此时Data可以不用出现 */
} AdjList[MaxVertexNum];    /* AdjList是邻接表类型 */

/* 图结点的定义 */
typedef struct GNode *PtrToGNode;
struct GNode {
    int Nv;     /* 顶点数 */
    int Ne;     /* 边数   */
    AdjList G;  /* 邻接表 */
};
typedef PtrToGNode LGraph; /* 以邻接表方式存储的图类型 */

LGraph CreateGraph(int VertexNum);

void InsertEdge(LGraph Graph, Edge E);

LGraph BuildGraph();

#endif

#endif //DATA_STRUCTURE_DS_GRAPH_H
