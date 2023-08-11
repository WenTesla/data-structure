// 已知在一维数组A[m+n]中依次存放两个线性表(a1,a2,a3,a4)和(b1,b2,b3)。
// 编写一个函数,将数组中两个顺序表的位置互换,即将(b1, b2, b3,…,b,)放在(a1,a2)的前面。
#include <stdio.h>
#define m 4
#define n 3
#define sum m + n
typedef int ElemType;
// 官方 逆置线性表
bool reverse(ElemType A[], int left, int right, int size)
{
    if (left >= right || right >= size)
    {

        return false;
    }
    // 逆置
    int mid = (left + right) / 2;
    for (int i = 0; i < mid - left; i++)
    {
        // 换
        ElemType temp = A[left + i];
        A[left + i] = A[right - i];
        A[right - i] = temp;
    }
    for (int i = 0; i < size; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
    return true;
};
// 官方 两次逆置 线性表
void Exchange(ElemType A[], int M, int N, int size)
{
    reverse(A, 0, M + N - 1, size);
    reverse(A, 0,M-1,size);
    reverse(A,M,M+N-1,size);

};

// 添加到新的线性表中
void reverse()
{
    // int sum = m + n;
    ElemType A[sum] = {1, 2, 3, 4, 5, 6, 7};
    int A_Length = sizeof(A) / sizeof(ElemType);
    ElemType B[sum];
    int k = 0;
    for (int i = m; i < m + n; i++)
    {
        B[k++] = A[i];
    }
    for (int i = 0; i < m; i++)
    {
        B[k++] = A[i];
    }
    for (int i = 0; i < m + n; i++)
    {
        printf("%d ", B[i]);
    }
}

int main()
{
    ElemType A[sum] = {1, 2, 3, 4, 5, 6, 7};
    Exchange(A,4,3,sum);
    // 4 6 5 7 1 2 3 
}
