/*
* remove element from the linked list 
* athor: hades
* email: hades2013ac@gmail.com
* date: 2018-3-8
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int intType_t;
typedef struct ListNode{
    intType_t element;
    struct ListNode *next;
}ListNode;

//初始化链表
void initList(ListNode *pNode){

    pNode = NULL;
    printf("%s函数执行，初始化链表成功\n",__FUNCTION__);
}

//打印链表
void printList(ListNode *pNode){

    if (pNode == NULL) {
        printf("%s函数执行，链表为空，打印失败\n",__FUNCTION__);
    }else{
        while (pNode != NULL) {
            printf("%d ",pNode->element);
            pNode = pNode->next;
        }
        printf("\n");
    }
}

//尾插法构建链表
ListNode *TailInsert(ListNode *pNode){

    ListNode *pInsert;
    ListNode *pMove;
    pInsert = (ListNode*)malloc(sizeof(ListNode));
    memset(pInsert, 0, sizeof(ListNode));
    pInsert->next = NULL;

    printf("输入元素值： \n");
    scanf("%d",&(pInsert->element));
    pMove = pNode;

    if (pInsert->element <= 0) {
        printf("%s函数执行，输入数据非法，建立链表停止\n",__FUNCTION__);
        return NULL;
    }

    while (pInsert->element > 0 ) {
        if (pNode == NULL) {
            pNode = pInsert;
            pMove = pNode;
        }else{

            while (pMove->next != NULL) {
                pMove = pMove->next;
            }
            pMove->next = pInsert;
        }
        pInsert = (ListNode*)malloc(sizeof(ListNode));
        memset(pInsert, 0, sizeof(ListNode));
        pInsert->next = NULL;
        printf("输入元素值： \n");
        scanf("%d",&(pInsert->element));
    }//while

    printf("%s函数执行，尾插法构建链表成功\n",__FUNCTION__);

    return pNode;
}

//获取链表长度
intType_t sizeList(ListNode *pNode){

    int i = 0;
    if (pNode == NULL) {
        printf("%s函数执行，链表为空，长度为0\n",__FUNCTION__);
        return 0;
    }else{

        while (pNode != NULL) {
            i++;
            pNode = pNode->next;
        }
        printf("%s函数执行，链表长度为%d\n",__FUNCTION__,i);
        return i;
    }
}

//删除pos位置的节点
ListNode *deletePosElement(ListNode *pNode,int pos){

    //需要一个头结点来维护
    ListNode *pHead;
    ListNode *pMove;
    int i = 1;
    if (pos <= 0 || pos > sizeList(pNode)) {
        printf("%s函数执行，输入pos值非法，删除节点失败\n",__FUNCTION__);
        return NULL;
    }

    pHead = pNode;
    pMove = pNode;
    //单独考虑删除第一个节点
    if (pos == 1) {

        pMove = pMove->next;
        pNode = pMove;
        free(pHead);

        printf("%s函数执行，删除pos=1位置元素成功\n",__FUNCTION__);
        return pNode;
    }

    while (pMove != NULL) {
        if (i == pos - 1) {
            break;
        }
        i++;
        pMove = pMove->next;
    }

    free(pMove->next);
    pMove->next = pMove->next->next;

    printf("%s函数执行，删除pos=%d位置元素成功\n",__FUNCTION__,pos);

    return pNode;
}

//判断x值是否在链表中，若存在则删除该节点
ListNode *deleteXElement(ListNode *pNode,int x){

    //一前一后两个指针，pMovePre是pMove的前一个节点
    ListNode *pMovePre;
    ListNode *pMove;

    if (pNode == NULL) {
        printf("%s函数执行，链表为空，删除x=%d失败\n",__FUNCTION__,x);
        return NULL;
    }

    pMovePre = pNode;
    pMove = pMovePre->next;

    //单独考虑第一个节点
    if (pMovePre->element == x) {
        pNode = pMove;
        free(pMovePre);
        return pNode;
    }

    while (pMove != NULL) {
        if (pMove->element == x) {
            //找到该节点的前一个节点
            pMovePre->next = pMove->next;
            free(pMove);
            break;
        }
        //同步前进
        pMove = pMove->next;
        pMovePre = pMovePre->next;
    }

    if (pMove == NULL) {
        printf("%s函数执行，不存在x=%d，删除数据失败\n",__FUNCTION__,x);
        return pNode;
    }

    printf("%s函数执行，删除x=%d成功\n",__FUNCTION__,x);
    return pNode;
}

int main(int argc, const char * argv[]) {

    ListNode *pList = NULL;

    //初始化
    initList(pList);
    printList(pList);

    //构建链表
    pList = TailInsert(pList);
    printList(pList);

    //获取链表长度
    sizeList(pList);

    //删除pos位置元素
    pList = deletePosElement(pList, 1);
    printList(pList);
    sizeList(pList);

    //判断x值是否在链表中，若存在则删除该节点
    pList = deleteXElement(pList,5);
    printList(pList);
    sizeList(pList);
    
    
    return 0;
}
