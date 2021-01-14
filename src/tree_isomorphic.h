//
// Created by young on 10/01/2021.
//

#ifndef DATA_STRUCTURE_TREE_ISOMORPHIC_H
#define DATA_STRUCTURE_TREE_ISOMORPHIC_H

#include <stdbool.h>

#define MaxTree 10
#define ElmenetType char
#define Tree int
#define Null -1

struct TreeNode{
    ElmenetType element;
    Tree Left;
    Tree Right;
}T1[MaxTree], T2[MaxTree];


Tree BuildTree(struct TreeNode T[]);

bool isomorphic(Tree r1, Tree r2);

#endif //DATA_STRUCTURE_TREE_ISOMORPHIC_H
