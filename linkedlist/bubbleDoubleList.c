/*
* 对不带头结点的非循环双向链表进行冒泡排序
* athor: hades
* email: hades2013ac@gmail.com
* date: 2018-3-10
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef int elemType;
typedef struct NodeList{

    int element;
    struct NodeList *prior;
    struct NodeList *next;
}ListNode;

//初始化不带头结点的非循环双向链表
void initList(ListNode *pNode){

    pNode = NULL;
    printf("%s函数执行，链表初始化完成\n",__FUNCTION__);
}

//创建非循环双向链表
ListNode *createList(ListNode *pNode){

    ListNode *pInsert;
    ListNode *pMove;
    pInsert = (ListNode*)malloc(sizeof(ListNode));
    memset(pInsert, 0, sizeof(ListNode));
    pInsert->next = NULL;
    pInsert->prior = NULL;

    printf("输入元素值： \n");
    scanf("%d",&(pInsert->element));
    pMove = pNode;

    if (pInsert->element <= 0) {

        printf("%s函数执行，输入数据非法，建立链表停止\n",__FUNCTION__);
        return NULL;
    }

    while (pInsert->element > 0) {
        if (pNode == NULL) {
            pNode = pInsert;
            pMove = pNode;
        }else{

            pMove->next = pInsert;
            pInsert->prior = pMove;
            pMove = pMove->next;
        }

        pInsert = (ListNode *)malloc(sizeof(ListNode));
        memset(pInsert, 0, sizeof(ListNode));
        pInsert->next = NULL;
        pInsert->prior = NULL;
        printf("输入元素值： \n");
        scanf("%d",&(pInsert->element));
    }

    printf("%s函数执行，建立链表成功\n",__FUNCTION__);

    return pNode;
}

//打印非循环双向链表
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

//返回不带头节点的双向链表的长度
int sizeList(ListNode *pNode){

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

//冒泡排序
ListNode *BubbleSort(ListNode *pNode){

    int count = sizeList(pNode);
    ListNode *pMove;
    pMove = pNode;
    while (count > 1) {
        while (pMove->next != NULL) {
            if (pMove->element > pMove->next->element) {
                int temp;
                temp = pMove->element;
                pMove->element = pMove->next->element;
                pMove->next->element = temp;
            }
            pMove = pMove->next;
        }
        count--;
        pMove = pNode;
    }

    printf("%s函数执行，冒泡排序完成\n",__FUNCTION__);
    return pNode;
}

int main(int argc, const char * argv[]) {

    ListNode *pList = NULL;

    initList(pList);
    printList(pList);

    pList = createList(pList);
    printList(pList);

    pList = BubbleSort(pList);
    printList(pList);

    return 0;
}

