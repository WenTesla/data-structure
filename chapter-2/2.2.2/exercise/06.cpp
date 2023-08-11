// 从有序表中删除所有值重复的值，

#include <stdio.h>

#define MaxSize 50

typedef int ElemType;
// 静态 长度从0 开始，表示线性表的长度
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
    printf("线性表中索引为%d元素%d已删除\n", i - 1, L.data[i - 1]);
    for (int j = i; j < L.length; j++)
    {
        L.data[j - 1] = L.data[j];
    }
    L.length--;
    return true;
};
// 双层循环，外层遍历所有值，内循环遍历重复的值
void ListDelDuplicate(SqlList &L, ElemType e)
{
    int tmp;
    // 遍历数组
    for (int i = 0; i < L.length; i++)
    {
        int cur = L.data[i];
        for (int j = i + 1; j < L.length;)
        {
            if (cur == L.data[j])
            {
                ListDelete(L, j + 1, tmp);
            }
            else
            {
                j++;
            }
        }
    }
};

// 官方
// 算法思想:注意是有序顺序表，值相同的元素一定在连续的位置上。
// 用类似于直接插入排序的思想，初始时将第一个元素视为非重复的有序表。
// 之后依次判断后面的元素是否与前面非重复有序表的最后一个元素相同，
// 若相同，则继续向后判断，若不同，则插入前面的非重复有序表的最后,直至判断到表尾为止。
bool Delete_Same(SqlList &L, ElemType e)
{
    if (L.length == 0)
    {
        return false;
    }

    ElemType cur = -1;
    //
    int i, j;
    for (i = 0, j = 1; j < L.length; j++)
    {
        if (L.data[i] != L.data[j])
        {
            L.data[++i] = L.data[j];
        }
    }

    L.length = i + 1;
    return true;
}

int main()
{
    SqlList l;
    // ListInsert(l, 1, 11);
    ListInsert(l, 1, 10);
    ListInsert(l, 1, 10);
    ListInsert(l, 1, 10);
    ListInsert(l, 1, 10);
    ListInsert(l, 1, 10);
    ListInsert(l, 1, 10);
    ListInsert(l, 1, 9);
    ListInsert(l, 1, 8);
    ListInsert(l, 1, 7);
    ListInsert(l, 1, 6);
    ListInsert(l, 1, 5);
    ListInsert(l, 1, 4);
    ListInsert(l, 1, 3);
    ListInsert(l, 1, 2);
    ListInsert(l, 1, 55);
    ListShow(l);
    // ListDelDuplicate(l, 10);
    Delete_Same(l, 10);
    ListShow(l);
}