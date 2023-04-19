#include <stdio.h>
#include <malloc.h>
#define MaxSize 50
typedef struct
{
    /* data */
    int data[MaxSize];
    int length;
} SqList;

int main()
{
    int array = [ 1, 2, 3 ];
    SqList s;
    s.length = 2;
    // s.data = (int *)malloc(sizeof(int) * 50);
    s.data=array;
    printf("%d", s.length);
}