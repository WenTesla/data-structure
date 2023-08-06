// 逆置顺序表 空间O(1)
#include <stdio.h>

#define MaxSize 50

typedef int ElemType;
// 静态
typedef struct
{
    ElemType data[MaxSize];
    int length = 0;
} SqlList;

// 在线性表的第i个位置插入新元素  1<=i<=L.length+1
bool ListInsert(SqlList &L, int i, ElemType e)
{
    // 判断i的范围是否有效
    if (i < 1 || i > L.length + 1)
    {
        return false;
    }
    // 当前存储空间已满
    if (i >= MaxSize)
    {
        return false;
    }

    // 将第i个元素后移
    for (int j = L.length; j >= i; j--)
    {
        L.data[j] = L.data[j - 1];
    }
    // 在i个位置放入e
    L.data[i - 1] = e;
    // 长度加一
    L.length++;
    return true;
};
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
void swap(ElemType &num1, ElemType &num2);

//
void ListReverse(SqlList &L)
{
    int start = 0;

    for (int i = 0; i < (L.length / 2); i++)
    {
        int j = L.length - 1 - i;
        /* code */
        swap(L.data[i], L.data[j]);

        /* code */
    }
}

void swap(ElemType &num1, ElemType &num2)
{
    ElemType tmp;
    tmp = num2;
    num2 = num1;
    num1 = tmp;
}

int main()
{
    SqlList l;
    ListInsert(l, 1, 1);
    ListInsert(l, 1, 2);
    ListInsert(l, 1, 3);
    ListInsert(l, 1, 4);
    ListInsert(l, 1, 5);
    ListShow(l);
    ListReverse(l);
    ListShow(l);
}
