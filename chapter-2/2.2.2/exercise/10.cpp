// 【2010统考真题】设将n (n >1）个整数存放到一维数组R中。
// 设计一个在时间和空间两方面都尽可能高效的算法。
// 将R中保存的序列循环左移p(0<p<n)个位置，即将R中的数据由(X0,X1,…,Xn-1)变换为(Xp…,Xp+1,..Xn-1,Xo,X…,Xp-1)。
// 要求:
// 1）给出算法的基本设计思想。
// 2）根据设计思想，采用C或C++或Java语言描述算法，关键之处给出注释。
// 3）说明你所设计算法的时间复杂度和空间复杂度。

// 设计思想
// 将ab 转为为ba，先将a逆置为a-1，然后将b逆置为b-1，然后将（a-1 b-1）逆置为（b a）

// 代码如下

//  时间复杂度 O(n) 逆置三次都是O(p)
//  空间复杂度 O(1) tmp变量
#include<stdio.h>
typedef int ElemType;
void Reverse(ElemType A[],int left,int riggt);
void CircleLeftShift(ElemType A[],int p,int size){
    Reverse(A,0,p-1);
    Reverse(A,p,size-1);
    Reverse(A,0,size-1);
};

// 官方 逆置线性表 参数为索引
void Reverse(ElemType A[], int left, int right)
{
  for (int i = 0 ; i < (right -  left +1) / 2; i++)
  {
    ElemType tmp = A[left + i];
    A[left + i] = A[right -i ];
    A[right - i] = tmp;
  }

};

int main(){
    ElemType A[] = {1,2,3,4,5,6,7,8};
    int size = sizeof(A)/ sizeof(ElemType);
    CircleLeftShift(A,1,size);
    for (auto &&i : A)
    {
        printf("%d ",i);
    }

}




