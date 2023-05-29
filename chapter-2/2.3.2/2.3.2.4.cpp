#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

LNode *LocateElem(LNode &L, int e)
{

    LNode *p = L.next;
    while (p != NULL)
    {
        if (p->data == e)
        {
            return p;
        }
        p = p->next;
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