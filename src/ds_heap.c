//
// Created by young on 10/01/2021.
//

#include "ds_heap.h"

MaxHeap create(int MaxSize) {
    MaxHeap H = malloc(sizeof(struct HeapStruct));
    H->Elements = malloc((MaxSize+1) * sizeof(ELementType));
    H->Size = 0;
    H->Capacity = MaxSize;
    H->Elements[0] = MaxData; // 哨兵, 大于堆中所有可能元素的值
}

bool is_full(MaxHeap H);

void insert(MaxHeap H, ELementType item) {
    // item 插入最大堆, 其中H->Element[0] 已经定义为哨兵

    int i;
    if (is_full(H)) return;

    i = ++H->Size;// i 指向插入后堆中的最后一个元素的位置

    for (;H->Elements[i/2]  < item; i/=2)
        H->Elements[i] = H->Elements[i/2]; // 向下过滤结点

    H->Elements[i] = item; // 插入

}

bool is_empty(MaxHeap H) {
    if (H->Size == 0) return ture;
    else return false;
}

ELementType delete_max(MaxHeap H) {
    int parent, child;
    ElementType MaxItem, tmp;

    if (is_empty(H)) return;

    MaxItem = H->Elements[1];// 删除的结点

    tmp = H->Elements[H->Size--];// 最后一个元素

    // 定位tmp结点位置, 从root结点开始向下搜索
    // 左儿子: 2i, 右儿子: 2i+1
    // parent*2 <= H->size : 判断是否有左儿子
    for (parent = 1; parent*2 <= H->Size ; parent = child) {
        child = parent * 2;

        // child != H->size 判断有没有右儿子
        if ( (child != H->Size) &&
            (H->Elements[child] < H->Elements[child+1]) )
            child++;
        if (temp >= H->Elements[child]) break;
        else
            H->Elements[parent] = H-> Elements[child];
    }
    H->Elements[parent] = tmp;

    return MaxItem;
}

// 最大的建立

oid PercDown( MaxHeap H, int p )
{
    /* 下滤：将H中以H->Data[p]为根的子堆调整为最大堆 */
    int Parent, Child;
    ElementType X;

    X = H->Data[p]; /* 取出根结点存放的值 */
    for( Parent=p; Parent*2<=H->Size; Parent=Child ) {
        Child = Parent * 2;
        if( (Child!=H->Size) && (H->Elements[Child]<H->Elements[Child+1]) )
            Child++;  /* Child指向左右子结点的较大者 */
        if( X >= H->Data[Child] ) break; /* 找到了合适位置 */
        else  /* 下滤X */
            H->Elements[Parent] = H->Elements[Child];
    }
    H->Elements[Parent] = X;
}

void BuildHeap( MaxHeap H )
{
    /* 调整H->Data[]中的元素，使满足最大堆的有序性  */
    /* 这里假设所有H->Size个元素已经存在H->Data[]中 */

    int i;

    /* 从最后一个结点的父节点开始，到根结点1 */
    for( i = H->Size/2; i>0; i-- )
        PercDown( H, i );
}
