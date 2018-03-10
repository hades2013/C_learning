/*
* 往带头结点尾结点的双向非循环链表中插入一个节点
* athor: hades
* email: hades2013ac@gmail.com
* date: 2018-3-10
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef int intType_t;
typedef struct NodeList{

    int element;
    struct NodeList *prior;
    struct NodeList *next;
}ListNode;

//初始化带头结点和尾结点的非循环双向链表
void InitialList(ListNode **pHead,ListNode **pTail){

    *pHead = (ListNode *)malloc(sizeof(ListNode));
    *pTail = (ListNode *)malloc(sizeof(ListNode));

    if (*pHead == NULL || *pTail == NULL) {
        printf("%s函数执行，内存分配失败，初始化双链表失败\n",__FUNCTION__);
    }else{
        //这个里面是关键，也是判空的重要条件
        (*pHead)->prior = NULL;
        (*pTail)->next = NULL;

        //链表为空的时候把头结点和尾结点连起来
        (*pHead)->next = *pTail;
        (*pTail)->prior = *pHead;

        printf("%s函数执行，带头结点和尾节点的双向非循环链表初始化成功\n",__FUNCTION__);
    }
}

//创建带头结点和尾结点的双向非循环链表
void CreateList(ListNode *pHead,ListNode *pTail){

    ListNode *pInsert;
    ListNode *pMove;
    pInsert = (ListNode*)malloc(sizeof(ListNode));
    memset(pInsert, 0, sizeof(ListNode));
    pInsert->prior = NULL;
    pInsert->next = NULL;

    printf("输入元素值： \n");
    scanf("%d",&(pInsert->element));
    pMove = pHead;
    while (pInsert->element > 0) {

        pMove->next = pInsert;
        pInsert->prior = pMove;
        pInsert->next = pTail;
        pTail->prior = pInsert;
        pMove = pInsert;

        pInsert = (ListNode *)malloc(sizeof(ListNode));
        memset(pInsert, 0, sizeof(ListNode));
        pInsert->prior = NULL;
        pInsert->next = NULL;
        printf("输入元素值： \n");
        scanf("%d",&(pInsert->element));
    }

    printf("%s函数执行完成，带头节点和尾结点的双向非循环链表创建成功\n",__FUNCTION__);

}

//正序打印链表
void PrintList(ListNode *pHead,ListNode *pTail){

    ListNode *pMove;
    pMove = pHead->next;
    while (pMove != pTail) {
        printf("%d ",pMove->element);
        pMove = pMove->next;
    }
    
    printf("\n%s函数执行，正序打印带头结点尾结点的双向非循环链表创建成功\n",__FUNCTION__);
}

//插入一个节点
//插入位置分别为0,1,2,.....
int InsertNodeList(ListNode *pHead,ListNode *pTail,int pos,int x){

    int i = 0;
    ListNode *pMove;
    ListNode *pInsert;
    pInsert = (ListNode *)malloc(sizeof(ListNode));
    memset(pInsert, 0, sizeof(ListNode));
    pInsert->prior = NULL;
    pInsert->next = NULL;
    pInsert->element = x;

    pMove = pHead;
    while (pMove != pTail) {
        if (i == pos) {
            //注意这里的链接顺序
            pMove->next->prior = pInsert;
            pInsert->next = pMove->next;
            pMove->next = pInsert;
            pInsert->prior = pMove;

            printf("%s函数执行，在pos=%d位置插入x=%d节点成功\n",__FUNCTION__,pos,x);
            return 1;
        }
        i++;
        pMove = pMove->next;
    }

    printf("%s函数执行，插入元素失败\n",__FUNCTION__);

    return 0;
}

//删除pos位置的节点
int DeletePosList(ListNode *pHead,ListNode *pTail,int pos){

    int i = 1;
    ListNode *pMove;
    pMove = pHead->next;
    while (pMove != pTail) {
        if (i == pos) {
            pMove->prior->next = pMove->next;
            pMove->next->prior = pMove->prior;
            free(pMove);
            pMove = NULL;
            printf("%s函数执行，删除pos=%d位置的节点成功\n",__FUNCTION__,pos);
            return 1;
        }
        i++;
        pMove = pMove->next;
    }
    printf("%s函数执行，删除pos=%d位置的节点失败\n",__FUNCTION__,pos);
    return 0;
}

//删除值为x的节点，若存在该节点则删除之
int DeleteValueList(ListNode *pHead,ListNode *pTail,int x){

    ListNode *pMove;
    pMove = pHead->next;
    while (pMove != pTail) {
        if (pMove->element == x) {
            pMove->prior->next = pMove->next;
            pMove->next->prior = pMove->prior;
            free(pMove);
            pMove = NULL;
            printf("%s函数执行，删除值为x=%d的节点成功\n",__FUNCTION__,x);
            return 1;
        }
        pMove = pMove->next;
    }

    printf("%s函数执行，删除值为x的节点失败\n",__FUNCTION__);
    return 0;
}

int main(int argc, const char * argv[]) {

    ListNode *pHead = NULL;//头结点
    ListNode *pTail = NULL;//尾结点

    InitialList(&pHead, &pTail);

    CreateList(pHead, pTail);
    PrintList(pHead, pTail);

    InsertNodeList(pHead,pTail,5,1111);
    PrintList(pHead, pTail);


    DeletePosList(pHead, pTail, 2);
    PrintList(pHead, pTail);

    DeleteValueList(pHead, pTail, 5);
    PrintList(pHead, pTail);

    return 0;
}