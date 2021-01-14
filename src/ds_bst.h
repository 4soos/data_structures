//
// Created by young on 10/01/2021.
//

#ifndef DATA_STRUCTURE_DS_BST_H
#define DATA_STRUCTURE_DS_BST_H

#include "common.h"
#include "ds_tree.h"

Position Find(ElementType X, BinTree BST);

Position FindMin(BinTree BST);

Position FindMax(BinTree BST);

BinTree Insert(ElementType X, BinTree BST);

BinTree Delete(ElementType X, BinTree BST);


#endif //DATA_STRUCTURE_DS_BST_H
