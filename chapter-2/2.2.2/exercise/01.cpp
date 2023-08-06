// 从顺序表中删除最小的元素并返回值，空出的元素由最后一个元素填充，若空则显示错误信息返回

#include <stdio.h>

#define MaxSize 50

typedef int ElemType;
// 静态
typedef struct
{
    ElemType data[MaxSize];
    int length = 0;
} SqlList;

bool DelMinElem(SqlList &L, ElemType &e)
{
    //
    if (L.length == 0)
    {
        return false;
    }
    // 赋值e
    // 定义位置
    int pos = 0;
    e = L.data[L.length - 1];
    // 遍历
    for (int i = L.length - 1; i >= 0; i--)
    {
        if (e > L.data[i])
        {
            e = L.data[i];
            pos = i;
        }
    }
    // 填充元素
    L.data[pos] = L.data[L.length - 1];
    L.length--;
    return true;
}

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

int main(int argc, char const *argv[])
{
    ElemType array[MaxSize];
    SqlList l;
    ListInsert(l, 1, 1);
    ListInsert(l, 2, 2);
    ListInsert(l, 3, 3);
    ListInsert(l, 3, 8);
    ListShow(l);
    ElemType min;
    DelMinElem(l, min);
    printf("最小值为%d\n", min);
    ListShow(l);
    return 0;
}