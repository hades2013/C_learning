
#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

int main()
{
	int i;
	data_t x;
	linklist_t p;
	p =	CreateEmptyLinklist();
	data_t a[10] = {1,3,5,7,9,11,13,15,17,19};

	for(i = 0;i < 10;i++)
	{
		InsertLinklist(p,i,a[i]);
	}

	ReverseLinklist(p);
	printf("The length of the list is:%d\n",LengthLinklist(p));
	
	GetLinklist(p,4,&x);
	printf("The NO.4 of this list is:%d\n",x);

	SetLinklist(p,4,100);
	GetLinklist(p,4,&x);
	printf("After updating!The No.4 0f this list is:%d\n",x);

	DeleteLinklist(p,4);
	printf("After updating!The length of the list is:%d\n",LengthLinklist(p));
	GetLinklist(p,4,&x);
	printf("After updating!The No.4 0f this list is:%d\n",x);

	ReverseLinklist(p);
	
	ClearLinklist(p);
	if(EmptyLinklist(p))
		printf("This list is empty!\n");
	DestroyLinklist(p);
	printf("This list is destroyed!\n");

	return 0;
	
}