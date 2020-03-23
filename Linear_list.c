#include <stdio.h>
#include <malloc.h>
#define LIST_INIT_SIZE 100
#define LIST_INCREAMENT 10
typedef enum{
    success,
    fail,
    fatal,
    range_error,
}Status;
typedef int ElemType;    // 处理 de 数据类型

typedef struct SqList
{
    ElemType *elem;
    int length;
    int list_size;
}SqList,*Ptr;
typedef Ptr SqListPtr;

/*           创建线性表          */
Status List_Init(SqListPtr L)  // 创建一个列表
{
    Status s = success;
    L->list_size = LIST_INIT_SIZE;
    L->length = 0;
    L->elem = (ElemType *)malloc(sizeof(ElemType)*L->list_size);
    if(L->elem == NULL)
        s=fatal;
    return s;
}


/*      查找数据----按位置查找        */
Status List_Retrival(SqListPtr L,int pos, ElemType *elem)
{
    Status s = range_error;
    if(L){
        if ((pos-1) >= 0&&(pos-1) < L->length){
            *elem = L->elem[pos-1];
            s = success;
        }
    }
    else
        s= fatal;
    return s;
}

/*      查找数据----按值查找位置        */
Status List_Locate(SqListPtr L,int pos, ElemType *elem)
{
    Status s = range_error;
    if(L){
        for(int i = 0;i<L->length; ++i){
            if(L->elem[i] == elem){
                pos = i+1;
                s = success;
                break;
            }
        }

    }
    else
        s= fatal;
    return s;
}

/*         插入元素操作       */

Status LIst_Insert(SqListPtr L,int pos, ElemType elem)
{
    Status s = range_error;
    if((pos-1) >= 0 && (pos-1) <= L->length){
        for (int i = L->length-1; i>= pos-1; --i){
            L->elem[i+1] = L->elem[i];
        }
        L->elem[pos-1] = elem;
        L->length++;
        s = success;
    }
    else
        s= fatal;
    return s;
}

/*         删除元素操作       */
Status List_Delete(SqListPtr L, int pos, ElemType elem)
{
    Status s = range_error;
    if((pos-1) >= 0 && (pos-1) <= L->length){
        if(L && L->length >0){
            for(int i = pos-1;i <= L->length-1; i++){
                L->elem[i] = L->elem[i+1];
            }
            L->length--;
            s = success;
        }
    }
    else
        s=fail;
    return s;
}



int main()
{
    return 0;
}
