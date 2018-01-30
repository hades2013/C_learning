
#include <stdio.h>
#include <stdlib.h>
//#include "datatype.h"
#include "seqlist.h"


void iterate_list(seqlist_t *list)
{
	int i;
	
	printf("list.last = %d, list = {", list->last);
	
	for (i = -1; i < list->last;) {
		printf("%d,", list->data[++i]);
	}
		
	if (LengthSqlist(list) > 0)
		printf("\b}\n");
	else
		printf("}\n");

}

int main(int argc, const char *argv[])
{
	int i;
	int length;
	data_t a[10] = {2,4,6,8,10,12,14,16,18,20};
	data_t x;
	seqlist_t *list;
	list = CreateEmptySqlist();

	if (list == NULL)
		return -1;

	for(i = 0; i < 10;i++)
	{
		if((InsertSqlist(list,i,a[i])) < 0)
			break;
	}
	iterate_list(list);
	length = LengthSqlist(list);
	printf("The length of the list is %d\n",length);

	GetSqlist(list,4,&x);
	printf("The NO.4 data of the list is %d\n",x);
	SetSqlist(list,4,5);
	GetSqlist(list,4,&x);
	printf("After updataing! The NO.4 data of the list is %d\n",x);

	printf("Delete data[4]!\n");
	DeleteSqlist(list,4);
	GetSqlist(list,4,&x);
	printf("Now data[4] = %d\n",x);
	printf("Now the legth of the list is %d\n",LengthSqlist(list));

	ClearSqlist(list);
	if(EmptySqlist(list))
		printf("The list is empty!\n");

	printf("Now the legth of the list is %d\n",LengthSqlist(list));

	DestroySqlist(list);

	printf("The list is destroyed!\n");

	return 0;
}