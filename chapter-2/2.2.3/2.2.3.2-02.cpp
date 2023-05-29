#include <stdio.h>
#define MaxSize 50

typedef int ElemType;

typedef struct
{
    ElemType data[MaxSize];
    int length = 0;
} SqlList;

// 将顺序表所有元素逆置 双指针
bool invertList(SqlList &L)
{
    int i = 0;
    int j = L.length - 1;
    int temp;
    while (i <= j)
    {
        temp = L.data[i];
        L.data[i] = L.data[j];
        L.data[j] = temp;
        i++;
        j--;
    }

    return true;
}

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

void initList(SqlList &L)
{
    for (int i = 0; i < MaxSize; i++)
    {
        L.data[i] = i;
        L.length++;
    }
}
int main()
{
    SqlList l;
    initList(l);
    ListShow(l);
    invertList(l);
    ListShow(l);
}