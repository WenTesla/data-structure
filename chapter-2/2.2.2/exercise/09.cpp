// 线性表(a1, a2, a3…,an)中的元素递增有序且按顺序存储于计算机内。
// 要求设计一个算法，完成用最少时间
// 在表中查找数值为x的元素，若找到，则将其与后继元素位置相交换
// 若找不到，则将其插入表中并使表中元素仍递增有序.

#include "common.h"

bool ListFind(SqlList &L, ElemType x)
{

    //
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] == x)
        {
            // 交换后续元素
            ElemType tmp = L.data[i + 1];
            L.data[i + 1] = L.data[i];
            L.data[i] = tmp;
            return true;
        }
        if (L.data[i] > x || i == L.length - 1)
        {
            // 插入
            ListInsert(L, i + 2, x);
            return false;
        }
    }
    return false;
};
// 官方 折半查找
void SearchExchangeInsert(ElemType A[], ElemType x, int size)
{
    int low = 0;
    // error
    // 这是因为在函数中，数组A被当作指针来处理。sizeof(A)返回的是指针A的大小，而不是数组A的大小。
    // 因此，high的值就是指针A的大小除以ElemType类型的大小，
    // 即high = sizeof(A) / sizeof(ElemType)。这个值通常比数组A的长度大1。
    // int high = sizeof(A)/sizeof(ElemType);
    // printf("%d",high);
    int high = size;

    int mid = -1;
    // 折半
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (A[mid] == x)
        {
            break;
        }
        if (A[mid] < x)
        {
            // 向右
            low = mid + 1;
        }
        if (A[mid] > x)
        {
            high = mid - 1;
        }
    }
    // 找到
    if (A[mid] == x && mid != size - 1)
    {
        // 交换后续元素
        ElemType tmp = A[mid];
        A[mid] = A[mid+1];
        A[mid+1] = tmp;
    }
    // 没找到
    if (low > high)
    {
        int i;
        // 后移
        for (i = size - 1; i > high ; i--)
        {
            A[i+1] = A[i];
        }
        A[i+1] =  x;
    }
    

    printf("索引为%d", mid);
};

int MyFunction()
{
    SqlList l;
    ListInsert(l, 1, 4);
    ListInsert(l, 1, 3);
    ListInsert(l, 1, 2);
    ListInsert(l, 1, 1);
    ListShow(l);
    bool isFind = ListFind(l, 2);
    ListShow(l);
    printf("%d", isFind);
}

int main()
{
    ElemType A[] = {1, 2, 3, 5, 7, 9};
    int size = sizeof(A) / sizeof(ElemType);
    SearchExchangeInsert(A, 10, size);
}