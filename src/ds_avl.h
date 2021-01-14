//
// Created by young on 10/01/2021.
//

#ifndef DATA_STRUCTURE_DS_AVL_H
#define DATA_STRUCTURE_DS_AVL_H

#include "common.h"

// Balance Factor : BT(T) = H_l - H_r
// 平衡二叉树的任一结点的左右子树高度差绝对值不超过1, |BF(T)| <= 1
// 平衡二叉树的最大树高: O( log_2(n) )
// 最少结点数: n_h = n_(h-1) + n_(h-2) + 1

typedef struct AVLNode *Position;
typedef Position AVLTree;

struct AVLNode {
    ElementType Data;
    AVLTree Left;
    AVLTree Right;
    int Height;
};



#endif //DATA_STRUCTURE_DS_AVL_H
