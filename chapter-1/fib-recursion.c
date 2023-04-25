//  递归实现斐波那契数列的和
#include <stdio.h>

int fib(int n)
{
    if (n == 1 || n == 2)
    {
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}

int main()
{
    int n;
    scanf("%d", &n);
    int count = fib(n);
    printf("%d\n", count);
    return 0;
}
