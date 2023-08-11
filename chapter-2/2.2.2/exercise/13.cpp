// 【2018统考真题】给定一个含n (n≥1）个整数的数组，
// 请设计一个在时间上尽可能高效的算法，找出数组中未出现的最小正整数。
// 例如，数组{-5,3,2,3}中未出现的最小正整数是1;数组{1,2,3}中未出现的最小正整数是4。
// 要求:
// 1)给出算法的基本设计思想。

// 2）根据设计思想，采用C或C++语言描述算法，关键之处给出注释。

// 3）说明你所设计算法的时间复杂度和空间复杂度。
// 时间 O(n^2) O(1)

#include <stdio.h>

int FindMinPositiveIntege(int A[], int size)
{
    int x = 1;
    int temp;
    // 先排序
    // 冒泡排序算法：进行 n-1 轮比较
    for (int i = 0; i < size - 1; i++)
    {
        // 每一轮比较前 n-1-i 个，也就是说，已经排序好的最后 i 个不用比较
        for (int j = 0; j < size - i - 1; j++)
        {
            if (A[j] > A[j + 1])
            {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    };
    for (int i = 0; i < size; i++)
    {
        printf("%d ", A[i]);
    }

    for (int i = 0; i < size; i++)
    {
        if (x == A[i] && A[i] > 0)
        {
            x++;
        }
    }
    return x;
}
// 官方
// 设计思想:使用时间换空间，定义一个用来标记的数组B[n]，用来标记数组A是否出现1-n的正整数
// B[0] -> 1 B[n-1] -> n 初始化B全为0，由于A的值含有n个整数，所以返回值是1-n+1，当A为1-n的时候，返回值为n+1
// 当数组A出现大于n的数的时候，数组B会空缺一个位置，这个位置就是所求的值
// 开始遍历当 0 < A[i] <=n 填入
// 否则舍弃

// 1)给出算法的基本设计思想。

// 2）根据设计思想，采用C或C++语言描述算法，关键之处给出注释。

// 3）说明你所设计算法的时间复杂度和空间复杂度。
// 时间 O(n) O(n)


int FindMissMin(int A[], int n)
{
    int B[n] = {0};
    int i;
    for (i = 0; i < n; i++)
    {
        if (A[i] > 0 && A[i] <= n)
        {
            B[A[i] - 1] = 1;
        }
    }
    for (i = 0; i < n; i++)
    {
        printf("%d ", B[i]);
        if (B[i] == 0)
            break;
    }
    return i + 1;
}
int main()
{
    int A[] = {-5, 3, 2, 3};
    int B[] = {1, 2, 3};

    // int x = FindMinPositiveIntege(B, 3);
    int x = FindMissMin(A, 4);
    printf("\n%d", x);
}