/*
* 使用动态数组来实现循环队列
* athor: hades
* email: hades2013ac@gmail.com
* date: 2018-3-10
*/

#include <stdio.h>
#include <stdlib.h>

static int *queue;//声明数组
static int maxSize;//数组大小
static int head;//指向头部
static int tail;//指向尾部

//Queue *queue;
//初始化队列
void InitQueue(int size){

    maxSize = size;
    queue = (int *)malloc(size * sizeof(int));
    head = 0;
    tail = 0;
}

//进队列
void EnQueue(int value){
    //先判断是否已满
    if ((tail + 1) % maxSize == head) {
        printf("队列已满，无法插入\n");
    }else{
        //未满
        queue[tail] = value;
        tail = (tail + 1) % maxSize;
    }
}

//出队列
int DeQueue(){

    int temp;
    //先判断是否为空
    if (head == tail) {
        printf("队列为空，出列失败\n");
    }else{

        temp = head;
        head = (head + 1) % maxSize;
    }

    return temp;
}

//判断队列是否为空
int IsEmpty(){
    if (head == tail) {
        printf("队列为空\n");
        return 1;
    }

    printf("队列不为空\n");
    return 0;
}

//判断队列是否已满
int IsFull(){

    if ((tail + 1)% maxSize == head) {
        printf("队列已满\n");
        return 1;
    }

    printf("队列未满\n");
    return 0;
}

//打印队列元素
void PrintQueue(){
    int i; 
    for (i = head; i < tail; i++) {
        printf("%d ",queue[i]);
    }
    printf("\n");
}


int main(int argc, const char * argv[]) {

    InitQueue(5);

    EnQueue(2);
    EnQueue(4);
    EnQueue(8);
    EnQueue(1);
    EnQueue(5);
    PrintQueue();

    DeQueue();DeQueue();DeQueue();
    PrintQueue();

    IsEmpty();
    IsFull();

    return 0;
}
