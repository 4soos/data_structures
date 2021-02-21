# Data Structures
数据从逻辑存储上来理解可以分为线性和非线性：

## 线性结构

### Array
某一种类型元素的集合，通过索引标记元素位置，数组中的元素在内存中是连续存储的，且每个元素占用相同大小的内存。
#### Python
Python中的三种基础类型：
* list 
* tuple
* range
可以使用｀list｀完成array相关操作
｀｀｀bash
>>> array_a = []
>>> array_a[0] = 1
>>> array_a.append(1)
>>> array_a[0]

>>> dir(array_a)
['__add__', '__class__', '__class_getitem__', '__contains__', '__delattr__', '__delitem__', '__dir__', '__doc__', '__eq__', '__format__', '__ge__', '__getattribute__', '__getitem__', '__gt__', '__hash__', '__iadd__', '__imul__', '__init__', '__init_subclass__', '__iter__', '__le__', '__len__', '__lt__', '__mul__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__reversed__', '__rmul__', '__setattr__', '__setitem__', '__sizeof__', '__str__', '__subclasshook__', 'append', 'clear', 'copy', 'count', 'extend', 'index', 'insert', 'pop', 'remove', 'reverse', 'sort']
>>>
｀｀｀

#### C&CPP

C中数组
```C
//typename arr-name [size];
int arr_a[10]; // 声明, 数组名表示的就是数组第一个元素的地址
int *pa;
pa = &arr_a[0];
int x = pa;

printf("%d", x);

char c = "Hello";// char s[] 等价于 char *s
//    printf("string's length %d", strlen(c));

double balance[5] = {1000.0, 2.0, 3.4, 7.0, 50.0};
printf("\n double array \n");
for (int i = 0; i < (sizeof(balance) / sizeof(balance[0])); i++) printf(" %d = %e \n", i, balance[i]);

/* 一个带有 5 行 2 列的数组 */
int a[5][2] = {{0, 0},
                {1, 2},
                {2, 4},
                {3, 6},
                {4, 8}};
int i, j;

/* 输出数组中每个元素的值 */
for (i = 0; i < 5; i++) {
    for (j = 0; j < 2; j++) {
        printf("a[%d][%d] = %d\n", i, j, a[i][j]);
    }
}
```

#### Rust

```Rust
fn main() {
    let a = [1, 2, 3, 4, 5];
    let b: [i32; 5] = [1, 2, 3, 4, 5];
    
    let first = a[0];
    let second = b[1];
}
```

> 使用 `tuple` 作为可以存储不同元素的数组
> ```Rust
>fn main() {
>    let x: (i32, f64, u8) = (500, 6.4, 1);
>
>    let five_hundred = x.0;
>
>    let six_point_four = x.1;
>
>    let one = x.2;
>}
>```


### Linked List
与数组很相似，过引用字段将所有分离的元素链接在一起，元素在内存中不是连续存储的。
通常由数据和对其他元素应用字段组成。

#### C
定义 
```C
#ifndef _List_H
struct Node;

typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

typedef ElementType int;

struct Node {
    ElementType data;
    Position Next;
}


#endif /* _List_H */

```

#### Stack

#### Queue

### 非线性

#### Tree
#### Heap
#### Hashing
#### Graph
 