/*
* insert linked list from head or tail  
* athor: hades
* email: hades2013ac@gmail.com
* date: 2018-3-8
*/

#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
  
typedef int intType_t;  
//构造节点  
typedef struct ListNode{  
    intType_t element;  
    struct ListNode *next;  
}ListNode;  
  
//初始化链表  
void initList(ListNode *pNode){  
  
    pNode = NULL;  
    printf("%s函数执行，头结点初始化完成\n",__FUNCTION__);  
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
  
//头插法  
ListNode *HeadInsert(ListNode *pNode){  
  
    ListNode *pInsert;  
    pInsert = (ListNode *)malloc(sizeof(ListNode));  
    if (pInsert == NULL) {  
        printf("%s函数执行，内存分配失败，建立链表失败\n",__FUNCTION__);  
        return NULL;  
    }  
  
    memset(pInsert, 0, sizeof(ListNode)); 
    printf("输入元素值： \n"); 
    scanf("%d",&(pInsert->element));  
    pInsert->next = NULL;  
  
    if (pInsert->element <= 0) {  
        printf("%s函数执行，输入数据有误，建立链表失败\n",__FUNCTION__);  
        return NULL;  
    }  
  
    while (pInsert->element > 0) {  
  
        if (pNode == NULL) {  
            pNode = pInsert;  
        }else{  
            //注意下面语句的顺序，否则可能造成链断裂  
            pInsert->next = pNode;  
            pNode = pInsert;  
        }  
  
        pInsert = (ListNode *)malloc(sizeof(ListNode));  
        if (pInsert == NULL) {  
            printf("%s函数执行，内存分配失败，建立链表失败\n",__FUNCTION__);  
            return NULL;  
        }  
  
        memset(pInsert, 0, sizeof(ListNode));
        printf("输入元素值： \n");  
        scanf("%d",&(pInsert->element));  
        pInsert->next = NULL;  
    }  
  
    printf("%s函数执行，头插法建立链表成功\n",__FUNCTION__);  
  
    return pNode;  
}  
  
//尾插法  
ListNode *TailInsert(ListNode *pNode){  
  
    ListNode *pInsert; //要插入的节点  
    ListNode *pMove; //遍历链表的节点  
    pInsert = (ListNode *)malloc(sizeof(ListNode));  
    if (pInsert == NULL) {  
        printf("%s函数执行，内存分配失败，建立链表失败\n",__FUNCTION__);  
        return NULL;  
    }  
  
    memset(pInsert, 0, sizeof(ListNode));
      
    printf("输入元素值： \n"); 
    scanf("%d",&(pInsert->element));  
    pInsert->next = NULL;  
  
    if (pInsert->element <= 0) {  
        printf("%s函数执行，输入数据有误，建立链表失败\n",__FUNCTION__);  
        return NULL;  
    }  
  
    pMove = pNode;  
    while (pInsert->element > 0) {  
        if (pNode == NULL) {  
            //注意不要忘了修改pMove指针的指向，初始pMove一定要指向头节点  
            pNode = pInsert;  
            pMove = pNode;  
        }else{  
            //遍历找到最后一个节点  
            while (pMove->next != NULL) {  
                pMove = pMove->next;  
            }  
            pMove->next = pInsert;  
        }  
  
        pInsert = (ListNode *)malloc(sizeof(ListNode));  
        if (pInsert == NULL) {  
            printf("%s函数执行，内存分配失败，建立链表失败\n",__FUNCTION__);  
            return NULL;  
        }  
  
        memset(pInsert, 0, sizeof(ListNode));  
        printf("输入元素值： \n"); 
        scanf("%d",&(pInsert->element));  
        pInsert->next = NULL;  
    } 
    
    printf("%s函数执行，尾插法建立链表成功\n",__FUNCTION__);  
    return pNode;  
}  
  
int main(int argc, const char * argv[]) {  
  
    ListNode *pList = NULL;  
  
    initList(pList);  
    printList(pList);  
  
    //头插法建立链表  
    pList = HeadInsert(pList);  
    printList(pList);  
  
    //尾插法建立链表  
    pList = TailInsert(pList);  
    printList(pList);  
  
    return 0;  
}  