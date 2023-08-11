// 将两个有序列表合并成一个新的有序列表,并由函数返回结果顺序表 (典型，牢固掌握)
#include "common.h"
// 双指针法 官方和我想得一样 
SqlList ListMerge(SqlList &L1, SqlList &L2)
{
    SqlList L;
    if (L1.length == 0 || L2.length == 0)
    {
        return L;
    }

    ElemType cur = L1.data[0];
    // L.length = L1.length + L2.length;
    int i = 0;
    int j = 0;
    int k = 1;
    ElemType big = -1;
    while (i < L1.length && j < L2.length)
    {
        if (L1.data[i] < L2.data[j])
        {
            ListInsert(L,k++,L1.data[i++]);
        }else
        {
            ListInsert(L,k++,L2.data[j++]);
        }
    }
    while (i < L1.length)
    {
        ListInsert(L,k++,L1.data[i++]);
    }
    while (j <L2.length)
    {
        ListInsert(L,k++,L2.data[j++]);
    }
    
    
    return L;
}

int main()
{
    SqlList l1;
    // ListInsert(l, 1, 11);
    ListInsert(l1, 1, 7);
    ListInsert(l1, 1, 4);
    ListInsert(l1, 1, 1);
    ListShow(l1);

    SqlList l2;
    ListInsert(l2, 1, 3);
    ListInsert(l2, 1,  2);
    ListInsert(l2, 1,  2);
    ListInsert(l2, 1,  1);
    ListShow(l2);
    SqlList l3 = ListMerge(l1, l2);
    ListShow(l3);
}
