/*
* single linked list 
* athor: hades
* email: hades2013ac@gmail.com
* date: 2018-3-8
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef int int_t; 

typedef struct ListNode {
	int_t element; 
	struct ListNode *next; 
	
}ListNode; 

void initList(ListNode *pNode)
{
	pNode = NULL; 
	printf("%s函数执行，初始化成功\n",__FUNCTION__);  
}

ListNode *createList(ListNode *pHead)
{
	ListNode *p1, *p2; 
	p1 = p2 = (ListNode *)malloc(sizeof(ListNode));
	if(p1 == NULL || p2 == NULL){
		printf("内存分配失败\n");  
        exit(0);
	} 
	memset(p1, 0, sizeof(ListNode)); 

	printf("输入元素值： \n");
	scanf("%d", &p1->element);
	p1->next = NULL; 
	while(p1->element > 0){    //输入的值大于0则继续，直到输入的值为负  
		if(pHead == NULL)
			pHead = p1; 
		else
			p2->next = p1; 
		p2 = p1; 
		p1 = (ListNode *)malloc(sizeof(ListNode));
		if(p1 == NULL){
			printf("内存分配失败\n");  
            exit(0); 
		}
		memset(p1, 0, sizeof(ListNode)); 
		printf("输入元素值： \n");
		scanf("%d", &p1->element);
		p1->next = NULL; 
	}
	printf("%s函数执行，链表创建成功\n",__FUNCTION__); 
	return pHead; 
}

void printList(ListNode *pHead)
{
	if(pHead == NULL)
		printf("%s函数执行，链表为空\n",__FUNCTION__);  
	else {
		while(pHead != NULL){
			printf("%d  ",pHead->element);
			pHead = pHead->next; 
		}
		printf("\n");
	}
}

void clearList(ListNode *pHead)
{
	ListNode *pNext; 
	if(pHead == NULL)
		 printf("%s函数执行，链表为空\n",__FUNCTION__);

	while(pHead->next != NULL && pHead != NULL){
		pNext = pHead->next; //保存下一结点的指针 
		free(pHead);
		pHead = NULL; 		 //释放当前节点 
		pHead = pNext;       //指向下一个节点  
	}
	printf("%s函数执行，链表已经清除\n",__FUNCTION__); 
}

int sizeList(ListNode *pHead)
{
	int size = 0; 
	while(pHead != NULL){
		size++; 
		pHead = pHead->next; 
	}
	printf("%s函数执行，链表长度 %d \n",__FUNCTION__,size);
	return size;   
}

int isEmptyList(ListNode *pHead)
{
	if(pHead == NULL){
		printf("%s函数执行，链表为空\n",__FUNCTION__);  
        return 1;  
	}
	printf("%s函数执行，链表非空\n",__FUNCTION__);  
    return 0;  
}

void getElement(ListNode *pHead, int pos)
{
	int i = 0; 
	if(pos < 1)
		 printf("%s函数执行，pos值非法\n",__FUNCTION__);

	if(pHead == NULL){  
        printf("%s函数执行，链表为空\n",__FUNCTION__);  
    }

    while(pHead != NULL){
    	i++; 
    	if(i == pos){
    		break; 
    	}
    	pHead = pHead->next; 
    }  
    if( i < pos)
    	printf("%s函数执行，pos值超出链表长度\n",__FUNCTION__);  
  
    printf("%s函数执行，位置 %d 中的元素为 %d\n",__FUNCTION__,pos,pHead->element);  
}

int_t *getElementAddr(ListNode *pHead, int_t x)
{
	if(pHead == NULL){
	 	printf("%s函数执行，链表为空\n",__FUNCTION__);  
        return NULL;  
    }  

   	while((pHead->element != x) && (pHead != NULL)){
   		pHead = pHead->next; 
   	}
   	if((pHead->element != x) && (pHead != NULL)){
   		printf("%s函数执行，在链表中未找到x值\n",__FUNCTION__);  
        return NULL;
   	}

   	if(pHead->element == x)
   		printf("%s函数执行，元素 %d 的地址为 0x%x\n",__FUNCTION__,x,&(pHead->element));  

   	return &(pHead->element);
}

int modifyElem(ListNode *pNode, int pos, int_t x)
{
	int i = 0;  
    if(NULL == pNode){  
        printf("%s函数执行，链表为空\n",__FUNCTION__);  
        return 0;  
    }  
  
    if(pos < 1){  
        printf("%s函数执行，pos值非法\n",__FUNCTION__);  
        return 0;  
    }  
  
    while(pNode != NULL){  
        i++;  
        if(i == pos){  
            break;  
        }  
        pNode = pNode->next; //移到下一结点  
    }  
  
    if(i < pos) {                 //pos值大于链表长度  
  
        printf("%s函数执行，pos值超出链表长度\n",__FUNCTION__);  
        return 0;  
    }  
    pNode->element = x;  
    printf("%s函数执行\n",__FUNCTION__);  
  
    return 1;  
}

int insertHeadList(ListNode **pNode, int_t insertElem)
{
	ListNode *pInsert; 
	pInsert = (ListNode *)malloc(sizeof(ListNode)); 
	memset(pInsert, 0, sizeof(ListNode));
	pInsert->element = insertElem; 
	pInsert->next = *pNode;
	*pNode = pInsert; 
	printf("%s函数执行，向表头插入元素成功\n",__FUNCTION__);  
    return 1;
}

int insertTailList(ListNode **pNode, int_t insertElem)
{
	ListNode *pInsert;
	ListNode *pHead; 

	pHead = *pNode; 
	pInsert = (ListNode *)malloc(sizeof(ListNode)); 
	memset(pInsert, 0, sizeof(ListNode));
	pInsert->element = insertElem;

	while(pHead->next != NULL){
		pHead = pHead->next; 
	}
	pHead->next = pInsert; 
	printf("%s函数执行，向表尾插入元素成功\n",__FUNCTION__);  
    return 1; 
}

int main(int argc, char const *argv[])
{
	ListNode *pList=NULL;            //声明头结点  
  
    initList(pList);       //链表初始化  
    printList(pList);       //遍历链表，打印链表  
  
    pList = createList(pList); //创建链表  
    printList(pList);  
  
    sizeList(pList);        //链表的长度  
    printList(pList);  
  
    isEmptyList(pList);     //判断链表是否为空链表  
  
    getElement(pList,3);  //获取第三个元素，如果元素不足3个，则返回0  
    printList(pList);  
  
    getElementAddr(pList,5);   //获得元素5的内存地址  
  
    modifyElem(pList,4,1);  //将链表中位置4上的元素修改为1  
    printList(pList);  
  
    insertHeadList(&pList,5);   //表头插入元素5  
    printList(pList);  
  
    insertTailList(&pList,10);  //表尾插入元素10  
    printList(pList);  
  
    clearList(pList);       //清空链表  
    printList(pList);  
   
	return 0;
}