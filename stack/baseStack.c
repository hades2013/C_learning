#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h> 

typedef struct Node {
	int data;
	struct Node *pNext; 
}Node; 

typedef struct Stack {
	Node *pTop; 
	Node *pBottom;
}Stack; 

void init(Stack *Stack); 
void push(Stack *Stack, int data);
void traverse(Stack *Stack);
int pop(Stack *Stack, int *pVal); 
int empty(Stack *Stack);
void clear(Stack *Stack); 

int main(int argc, char const *argv[])
{
	Stack s; 
	int val; 
	init(&s);

	push(&s, 1);
	push(&s, 2);
	push(&s, 3);
	push(&s, 4);
	push(&s, 5);
	push(&s, 6);

	traverse(&s);

	if(pop(&s, &val))
		printf("pop stack successed: %d\n", val);
	else 
		printf("pop stack failed\n");

	traverse(&s);
	clear(&s);
	traverse(&s); 
	return 0;
}
void init(Stack *Stack)
{
	Stack->pTop = (Node *)malloc(sizeof(Node));
	if(NULL == Stack->pTop){
		printf("it's malloc failed!\n");
		exit(-1); 
	}
	else{
		Stack->pBottom = Stack->pTop; 
		Stack->pTop->pNext = NULL; 
	}
}

void push(Stack *Stack, int data)
{
	Node *p = (Node *)malloc(sizeof(Node)); 
	p->data = data; 
	p->pNext = Stack->pTop; 
	Stack->pTop = p; 
}

void traverse(Stack *Stack)
{
	Node *p = Stack->pTop;
	while(p != Stack->pBottom){
		printf("%d ", p->data);
		p = p->pNext;
	}
	printf("\n");
	return;

}

int empty(Stack *Stack)
{
	if(Stack->pTop == Stack->pBottom)
		return 1; 
	else 
		return 0; 
}

int pop(Stack *Stack, int *pVal)
{
	if(empty(Stack))
		return 0; 
	else{
		Node *r = Stack->pTop; 
		*pVal = r->data; 
		Stack->pTop = r->pNext; 
		free(r);
		r = NULL; 
		return 1; 
	}
}

void clear(Stack *Stack)
{
	if(empty(Stack))
		return; 
	else{
		Node *p = Stack->pTop; 
		Node *q = NULL;
		while(p != Stack->pBottom){
			q = p->pNext; 
			free(q); 
			p = q; 
		} 
		Stack->pTop = Stack->pBottom; 
	}
}
