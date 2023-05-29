#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

LNode *GetElem(LNode &L, int i)
{
    if (i < 1)
    {
        return NULL;
    }
    int j = 1;
    LNode *p = L.next;
    while (p != NULL && j < i)
    {
        p = p->next;
        j++;
    }
    return p;
}
// 遍历单链表
void ListShow(LinkList &L)
{
    LinkList p = L->next;
    while (p != NULL)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
}
int main()
{
    LNode *l;

    ListShow(l);
}