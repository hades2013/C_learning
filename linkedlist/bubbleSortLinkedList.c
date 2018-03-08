/*
* bubble sort the linked list 
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

//链表实现冒泡排序
ListNode *BubbleSortLinkedList(ListNode *pNode){
    if (pNode == NULL) {
        printf("%s函数执行，链表为空，冒泡排序失败\n",__FUNCTION__);
        return NULL;
    }else{

        ListNode *pMove;
        pMove = pNode;
        int i; 
        //需要进行(n-1)次遍历,控制次数
        int size = sizeList(pNode);
        for (i = 0; i < size; i++) {
            while (pMove->next != NULL) {
                if (pMove->element > pMove->next->element) {
                    //只要交换这两个节点的element元素值就可以了
                    int temp;
                    temp = pMove->element;
                    pMove->element = pMove->next->element;
                    pMove->next->element = temp;
                }
                pMove = pMove->next;
            }
            //每次遍历结束，pMove重新移动到链表头部
            pMove = pNode;
        }
    }
    printf("%s函数执行，链表冒泡排序完成\n",__FUNCTION__);

    return pNode;
}

int main(int argc, const char * argv[]) {

    ListNode *pList = NULL;

    //初始化
    initList(pList);
    printList(pList);

    //尾插法建立链表
    pList = TailInsert(pList);
    printList(pList);

    //冒泡排序
    pList = BubbleSortLinkedList(pList);
    printList(pList);
      
    return 0;
}
