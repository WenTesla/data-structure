#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;


// 采用尾插法建立单链表
LinkList List_TailInsert(LinkList &L)
{
    
    LinkList s;
    ElemType x;
    // 初始化表头
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    // 表尾
    LinkList t = L;

    scanf("%d", &x);
    while (x != -1)
    {
        // 请求一个内存
        s = (LinkList)malloc(sizeof(LNode));
        s->data = x;
        t->next=s;
        t=t->next;
        // 或者
        // t=s;
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
    List_TailInsert(l);
    ListShow(l);
}