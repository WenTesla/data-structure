#include <stdio.h>
#define MaxSize 50

typedef int ElemType;

typedef struct
{
    ElemType data[MaxSize];
    int length = 0;
} SqlList;


// 遍历顺序表的所有元素
void ListShow(SqlList &L)
{
    for (int i = 0; i < L.length; i++)
    {
        printf("线性表中索引为%d的元素为 %d\n", i, L.data[i]);
    }
    printf("\n");
    return;
};

void initList(SqlList &L)
{
    for (int i = 0; i < MaxSize; i++)
    {
        L.data[i] = i;
        L.length++;
    }
}

// 对长度为n的顺序表L，编译一个时间复杂度为O(n)，空间复杂度为(1)的算法，删除线性表中所有值为x的数据元素。

