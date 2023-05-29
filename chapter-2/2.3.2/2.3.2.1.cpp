#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

// 采用头插法建立单链表
LinkList List_HeadInsert(LinkList &L)
{
    // 初始化头
    LinkList s;
    ElemType x;
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    scanf("请输入值:%d", &x);
    while (x != -1)
    {
        // 请求一个内存
        s = (LinkList)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d", &x);
    }
    return L;
};

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
    List_HeadInsert(l);
    ListShow(l);
}
