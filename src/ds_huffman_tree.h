//
// Created by young on 12/01/2021.
//

#ifndef DATA_STRUCTURE_DS_HUFFMAN_TREE_H
#define DATA_STRUCTURE_DS_HUFFMAN_TREE_H

#include "common.h"

typedef struct TreeNode *HuffmanTree;

struct TreeNode{
    int weight;
    HuffmanTree  Left, Right;
};

HuffmanTree Huffman(MinHeap H) ;

#endif //DATA_STRUCTURE_DS_HUFFMAN_TREE_H
