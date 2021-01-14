//
// Created by young on 10/01/2021.
//

#include "tree_isomorphic.h"

int main() {
    Tree R1, R2;

    R1 = BuildTree(T1);
    R2 = BuildTree(T2);

    if (isomorphic(R1, R2)) return true;
    else return fasle;

}

Tree BuildTree(struct TreeNode T[]) {
    int N;
    scanf("%d\n", &N);
    if (N) {
        for (int i = 0; i < N; i++) {
            scanf("%c %c %c \n", &T[i].element, &cl, &cr);
            //TODO
        }
    }
}

bool isomorphic(Tree r1, Tree r2) {
    if ((r1 == Null) && R2 == Null)
        return true;

    if (((r1 == Null) && (r2 != Null)) || ((r1 != Null) && (r2 == Null)))
        return false;

    if (T1[r1].element != T2[r2].element)
        return false;

    if ((T1[r1].Left == Null) && (T2[r2].Left) == Null)
        return isomorphic(T1[r1].Right, T2[r2].Right);

    if (((T1[r1].Left != Null) && (T2[r2].Left != Null)) &&
        ((T1[T1[r1].Left].element) == T2[T2[r2].Left].element))

        return (isomorphic(T1[r1].Left, T2[r2].Left) &&
                isomorphic(T1[r1].Right, T2[r2].Right));

    else
        return (isomorphic(T1[r1].Left, T2[r2].Right) &&
                isomorphic(T1[r1].Right, T2[r2].Left))
}
