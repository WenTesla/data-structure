
// 【2011 统考真题】一个长度为L(L≥1）的升序序列S，处在第[L/2个位置的数称为S的中位数。
// 例如，若序列S1=(11,13,15,17,19)，则S1的中位数是15，
// 两个序列的中位数是含它们所有元素的升序序列的中位数。
// 例如，若S2=(2,4,6,8,20)，则S1和S2的中位数是11。
// 现在有两个等长升序序列A和B，
// 试设计一个在时间和空间两方面都尽可能高效的算法，找出两个序列A和B的中位数。要求:

// 2 4 6 8 11 13 15 17 19 20 10个数 中位数第5个

// 1）给出算法的基本设计思想。
// 2）根据设计思想，采用C或C++或Java语言描述算法，关键之处给出注释。
// 3）说明你所设计笄法的时间复杂度和空间复杂度。

#include <stdio.h>
typedef int ElemType;

// 双指针
// 时间 O(n) 空间O(1)
ElemType FindMiddleNum(ElemType A[], ElemType B[], int length)
{
    int x = -1;
    int k = 0;
    int i, j;
    for (i = 0, j = 0; i < length || j < length;)
    {

        if (A[i] <= B[j])
        {
            k++;
            if (k == length)
            {
                return B[j];
            }
            i++;
        }
        else
        {
            k++;
            if (k == length)
            {
                return A[i];
            }
            j++;
        }
    }
    return -1;
};

// 官方
// 1）算法的基本设计思想如下。
// 分别求两个升序序列A、B的中位数，设为α和b，求序列A、B的中位数
// 过程:
// ①如1若a=b，则a或b即为所求中位数,算法结束。
// ②若a<b，则舍弃序列A中较小的一半，同时舍弃序列B中较大的一半，要求两次舍弃的长度相等。
// ③若a>b，则舍弃序列A中较大的一半，同时舍弃序列B中较小的一半，要求两次舍弃的长度相等。
// 在保留的两个升序序列中，重复过程①、②、③，直到两个序列中均只含一个元素时为止,较小者即为所求的中位数。

ElemType M_search(ElemType A[], ElemType B[], int n)
{
    int s1 = 0, d1 = n - 1, m1, s2 = 0, d2 = n - 1, m2;
    // A的首位数 末位数 中位数

    while (s1 != d1 || s2 != d2)
    {
        m1 = (s1 + d1) / 2;
        m2 = (s2 + d2) / 2;
        if (A[m1] == B[m2])
        {
            return A[m1];
        }
        if (A[m1] < B[m2])
        {
            // 如果为奇数
            if ((s1 + d1) % 2 == 0)
            {
                s1 = m1; // 且保留中间点
                d2 = m2;
            }
            else
            {
                s1 = m1 + 1;
                d2 = m2;
            }
        }
        else
        {
            if ((s2 + d2) % 2 == 0)
            {
                d1 = m1;
                s2 = m2;
            }
            else
            {
                d1 = m1;
                s2 = m2 + 1;
            }
        }
    }
    return A[s1] < B[s2] ? A[s1] : B[s2];
}
int main()
{
    ElemType A[] = {11, 13, 15, 17, 19};
    ElemType B[] = {2, 4, 6, 8, 20};
    ElemType C[] = {1, 2, 3, 5, 5};
    ElemType D[] = {6, 7, 8, 9, 10};
    int length = sizeof(A) / sizeof(ElemType);
    // ElemType x = FindMiddleNum(C, B, length - 1);
    ElemType x = M_search(C, B, length);
    printf("%d", x);
}
