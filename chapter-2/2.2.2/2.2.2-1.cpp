// 顺序表的插入操作
#include <stdio.h>
#define MaxSize 50

typedef int ElemType;

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
    L.data[i-1] = e;
    // 长度加一
    L.length++;
    return true;
};

// 删除表中第i个元素 1<=i<=L.length+1
bool ListDelete(SqlList &L, int i, ElemType &e)
{

    if (i < 1 || i > L.length)
    {
        return false;
    }
    e = L.data[i - 1];
    printf("元素%d已删除\n",L.data[i-1]);
    for (int j = i; j < L.length; j++)
    {
        L.data[j - 1] = L.data[j];
    }
    L.length--;
    return true;
};
// 在顺序表中查找第一个元素值等于e的元素
int LocateElem(SqlList &L, ElemType e)
{
    int i;
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] == e)
        {
            return i + 1;
        }
    }
    return -1;
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
int main()
{
    SqlList l;
    // 插入
    ListInsert(l,1,1);
    ListShow(l);
    ListInsert(l,2,2);
    ListShow(l);
    ListInsert(l,2,3);
    ListShow(l);
    ListInsert(l,2,4);
    ListShow(l);
    // 删除
    int e;
    ListDelete(l,2,e);
    ListShow(l);
    // 查找元素
    int index = LocateElem(l,2);
    printf("是第%d个元素",index);
    return 0;
}