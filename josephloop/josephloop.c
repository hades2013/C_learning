
#include <stdio.h>
#include <stdlib.h>

typedef int data_t;

typedef struct node_t
{
	data_t data;
	struct node_t *next; 	
}linknode_t,*linklist;

linklist CreateList(int n)
{
	int i;
	linklist p,head,tail;
	head = NULL;
	
	for(i = 1;i <= n;i++)
	{
		p = (linklist)malloc(sizeof(linklist));
		if(p == NULL)
		{
			printf("malloc fails!\n");
		}
			
		p->data = i;
		if(head == NULL)
		{
			head = p;
			tail = head;
		}
		else
		{
			tail->next = p;
		}				
		
		tail = p;
	}
	
	tail->next = head;

	return head; 
}

void Joseph(int n,int k,int m)
{
	int i;
	linklist p,r;
	p = CreateList(n);

	for(i = 1;i < k;i++) //从第K个人开始数
	{
		p = p->next;
	}

	while(p->next != p)
	{
		for(i = 1;i <= m-2;i++)  //数到第m个人，去自杀
			p = p->next;

		r = p->next;
		p->next = r->next;
		printf("%d->",r->data);
		
		free(r);
		p = p->next;//从下一个人继续数
	}
	
	printf("%d\n",p->data);
}

int main()
{
	Joseph(41,1,3);

	return 0;
}

