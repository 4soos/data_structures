//
// Created by young on 10/01/2021.
//

#ifndef DATA_STRUCTURE_DS_TREE_H
#define DATA_STRUCTURE_DS_TREE_H

#include "common.h"

typedef struct TNode *Position;
typedef Position BinTree;

struct TNode {
    ELementType Data;
    BinTree Left;
    BinTree Right;
};

/**
 * 二叉树重要性质:
 * 1. 第i层的最大节点数为: 2 ^(i-1), i>=1
 * 2. 深度为k的二叉树最大结点总数: 2^(k)-1 , k>=1
 * 3. 非空二叉树T, 若 n_(0) = n_(2) + 1
 */



#endif //DATA_STRUCTURE_DS_TREE_H
