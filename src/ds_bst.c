//
// Created by young on 10/01/2021.
//

#include "ds_bst.h"
#include "ds_tree.h"

Position Find(ElementType X, BinTree BST) {
    if (!BST)
        return NULL;

    if (X > BST->Data)
        return Find(X, BST->Right); // 尾递归
    else if (X < BST->Data)
        return Find(X, BST->Left); // 尾递归
    else
        return BST;
}

Position IterFind(ElementType X, BinTree BST) {
// 非递归的函数执行效率较高

    while (BST) {

        if (X > BST->Data)
            BST = BST->Right;
        else if (X < BST->Data)
            BST = BST->Left;
        else
            return BST;
    }

    return NULL;
}

Position FindMin(BinTree BST) {
    if (!BST) 
        return NULL;
    else if (!BST->Left)
        return BST;
    else
        return FindMin(BST->Left);
    
}

Position FindMax(BinTree BST) {
    if (BST)
        while (BST->Right) BST = BST->Right;
    return BST;
}


BinTree Insert(ElementType X, BinTree BST) {
    if (!BST) {
        BST = malloc(sizeof(struct TreeNode));
        BST->Data = X;
        BST->Left = BST->Right = NULL;
    } else {
        if (X < BST->Data)
            BST->Left = Insert(X, BST->Left);
        else if (X > BST-> Data) 
            BST->Right = Insert(X, BST->Right);
    }

    return BST;
}


BinTree Delete(ElementType X, BinTree BST) {
    Position tmp;
    if (!BST) return NULL;

    else if (X < BST->Data)
        BST->Left = Delete(X, BST->Left);

    else if (X > BST->Data)
        BST->Right = Delete(X, BST->Right);

    else 
        if (BST->Left && BST->Right) { /* 删除结点存在左右2个子节点 */
            tmp = FindMin(BST->Right); // 在右子树中找最小的元素填充删除结点

            BST->Data = tmp->Data;
            BST->Right = Delete(BST->Data, BST->Right); // 删除右子树中最小元素
        } else { /* 删除结点存在 1 or 0 个子节点 */
            tmp = BST;
            if (!BST->Left) // 存在右孩子或无节点
                BST = BST->Right;
            else if (!BST->Right) // 存在左孩子或无节点
                BST = BST->Left;
            free(tmp);
        }
    return BST;
}



