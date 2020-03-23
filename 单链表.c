#include <stdio.h>
#include <string.h>

typedef int ElemType;

typedef struct Node
{
    ElemType elem;
    struct Node *next;
}Node, *Ptr;
typedef Ptr *SqListPtr;
/*
    Node n1,n2;
    Ptr p = &n1;
    n1.next=&n2;
    SqListPtr L=p;
    n2.next=NULL;
*/
typedef enum{
    success,
    fail,
    fatal,
    range_error,
}Status;


/* 按位置查找元素 */
Status List_Retrieve(SqListPtr L, int pos, ElemType *elem)
{
    Status s = range_error;
    Ptr p = (*L)->next;/*  带头结点，移动 p指向第一个元素结点 指向第一个元素结点 */
    int i = 1;/* 计数器 */
    while(p && i<pos){/* p  指向的结点存在 ,且未到达指定位置 且未到达指定位置 *//* 条件１防止 pos>表长 ;条件２ 控制取第pos个, 防止pos<1 */
        ++i;
        p = p->next;
    }
    if(p && i == pos)/* 找到指定位置 ,且该结点存在 */
    {
        *elem = p->elem;
        s = success;
    }
    return s;
}

/* 按值查找元素 */
Status List_Locate(SqListPtr L, int pos, ElemType *elem)
{
    Status s = range_error;
    Ptr p = (*L)->next;
    int i = 1;
    while(p!=NUll)
    {
        if(p->elem == elem)break;
        ++i;
        p=p->next;
    }
    if(p){
        *pos = i;
        s = success;
    }
    return s;
}

int main()
{
    return 0;
}
