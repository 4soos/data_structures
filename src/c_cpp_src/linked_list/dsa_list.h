#ifndef _List_H

struct Node;
typedef struct Node *PtrToNode;
typedef struct PtrToNode List;
typedef struct PtrToNode Position;

typedef ElementType int; /*  */

struct Node {
    ElementType data;
    Position next;
};




#endif /* _List_H */