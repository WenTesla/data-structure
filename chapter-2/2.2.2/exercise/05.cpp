// 在顺序表中删除其值在定值s和t的所有元素（s<t)，若不合理或空，则显示错误

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
// 从后往前扫描顺序表，每遇到一个值在s和t之间，则删除一个元素，其后元素全部前移动 但这种算法效率不高
bool ListDelElems(SqlList &L, int min, int max)
{
    int tmp;
    int i, j;
    if (min > max || min < 0 || max > L.length || L.length == 0)
    {
        return false;
    }
    for (int i = L.length - 1; i >= 0; i--)
    {
        if (L.data[i] > min && L.data[i] < max)
        {
            ListDelete(L, i + 1, tmp);
        }
    }
    return true;
}
// 官方
// 算法思想:从前向后扫描顺序表L，用k记录下元素值在s到t之间元索的个数（初始时k=0)。
// 对于当前扫描的元素，若其值不在s到t之间，则前移k个位置;否则执行k++。
// 由于这样每个不在s到t之间的元素仅移动一次,因此算法效率高。
bool Del_s_t(SqlList &L, int min, int max)
{
    int k = 0;
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] > min && L.data[i] < max)
        {
            k++;
        }
        else
        {
            // 前移k个位置
            L.data[i] = L.data[i + k];
        }
    }
    return true;
}

int main()
{
    SqlList l;
    // ListInsert(l, 1, 11);
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
    ListDelElems(l, 3, 5);
    ListShow(l);
}
