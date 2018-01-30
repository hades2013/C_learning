
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

int JudgeIsloop(linklist list)
{
	int flag = 0;
	linknode_t *slow,*fast;

	if(list == NULL)
		return 0;

	slow = list;
	fast = list->next;

	while(slow)
	{
		if(fast == NULL || fast->next == NULL)//走到头了
			return 0;
		else if(fast == slow || fast->next == slow)//二者相遇，因为fast走的快，如果fast->next指向slow，也是循环的
		{	
			flag = 1;
			return 1;
		}
		else
		{
			slow = slow->next;//慢指针走一步
			fast = fast->next->next;//快指针走两步
		}
	}

	return 0;
}

int main()
{
	int i;
	int flag = 0;
	linklist list;
	list = CreateList(10);
	
	JudgeIsloop(list);

	if(flag = 0)
		printf("The list is not a looplist!\n");
	else
	{
		printf("The list is a looplist!\n");//循环链表则打印出来
		for(i = 0;i < 10;i++)
		{
			printf("%d->",list->data);
			list = list->next;
		}
		printf("%d\n",list->data);
	}

	return 0;
}

