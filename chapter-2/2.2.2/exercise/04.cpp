// 在有序的顺序表中删除其值在定值s和t的所有元素，若不合理或空，则显示错误

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
// 删除表中第i个元素 1<=i<=L.length+1
bool ListDelete(SqlList &L, int i, ElemType &e)
{

    if (i < 1 || i > L.length)
    {
        return false;
    }
    e = L.data[i - 1];
    printf("元素%d已删除\n", L.data[i - 1]);
    for (int j = i; j < L.length; j++)
    {
        L.data[j - 1] = L.data[j];
    }
    L.length--;
    return true;
};

bool ListDelElems(SqlList &L, int start, int end, ElemType e)
{
    if (start > end || start < 0 || end > L.length || L.length == 0)
    {
        return false;
    }

    while (L.data[start] == e)
    {
        ListDelete(L, start, e);
    }
    return true;
}

int main()
{
    SqlList l;
    ListInsert(l, 1, 1);
    ListInsert(l, 1, 2);
    ListInsert(l, 1, 3);
    ListInsert(l, 1, 4);
    ListInsert(l, 1, 5);
    ListInsert(l, 1, 5);
    ListInsert(l, 1, 5);
    ListInsert(l, 1, 5);
    ListInsert(l, 1, 5);
    ListShow(l);
    ListDelElems(l, 1, 6, 5);
    ListShow(l);
}