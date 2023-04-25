// 非递归实现斐波那契数列的和
#include <stdio.h>

int fib(int n)
{
    int f1, f2, f3;
    f1 = f2 = 1;
    if (n == 1 || n == 2)
    {
        return 1;
    }
    for (int i = 3; i <= n; i++)
    {
        f3 = f1 + f2;
        f1 = f2;
        f2 = f3;
    }

    return f3;
}

int main()
{
    int n;
    scanf("%d", &n);
    int count = fib(n);
    printf("%d\n", count);
}