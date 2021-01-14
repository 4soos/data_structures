//
// Created by young on 12/01/2021.
//

#include "ds_huffman_tree.h"

HuffmanTree Huffman(MinHeap H) {
    int i;
    HuffmanTree T;
    BuildMinHeap(H);
    for (i = 1; i < H->Size; i++) {
        T = malloc(sizeof(struct TreeNode));
        T->Left = DeleteMin(H);
        T->Right = DeleteMin();
        T->weight = T->Left->weight + T->Right->weight;

        Insert(H, T);
    }
    T =DeleteMin(H);
    return T;
}