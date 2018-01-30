
#include <stdio.h>
#include <stdlib.h>
#include "seqlist.h"

seqlist_t *CreateEmptySqlist()
{
	seqlist_t *list;
	list = (seqlist_t *)malloc(sizeof(seqlist_t));
	if(list != NULL)
	{
		list->last = -1;//list->last初始化，空表中，list-last = -1;
	}

	return list;
}

void DestroySqlist(seqlist_t *list)
{
	if (list == NULL)
		return ;
	
	free(list);

	return;
}

void ClearSqlist(seqlist_t *list)
{
	if (list == NULL)
		return ;

	list->last = -1;//清空线性表

}

int EmptySqlist(seqlist_t *list)
{
	if (list == NULL)
		return -1;
	
	if(list->last == -1)//空表的标志
		return 1;
	else
		return 0;
}

int FullSqlist(seqlist_t *list)
{
	if (list == NULL)
		return -1;

	if (MAX - 1 == list->last)
		return 1;
	else
		return 0;
}

int LengthSqlist(seqlist_t *list)
{
	if (list == NULL)
		return -1;
	else
		return (list->last + 1);
}

int GetSqlist(seqlist_t *list, int at, data_t *x) //data_t *x为出参
{
	if(list == NULL || at < 0 || at > list->last)
		return -1;

	*x = list->data[at];

	return 0;
}

int SetSqlist(seqlist_t *list, int at, data_t x)//data_t x为入参
{
	if(list == NULL || at < 0 || (at > list->last))
		return -1;

	list->data[at] = x;

	return 0;
}

int InsertSqlist(seqlist_t *list, int at, data_t x)
{
	int j;
	if(list == NULL || at < 0 || FullSqlist(list))
		return -1;

	if(at > list->last)//此情况比较特殊，如表中长度是50，却要插在60前面，我们这里将其插在50后面，即at = list->last + 1
	{
		at = list->last + 1;//若是空表{}，list->last为-1，此时将其放在第0位；
	}
	else
	{
		for(j = list->last; j >= at; j--)
		{
			list->data[j+1] = list->data[j];
		}
	}

	list->data[at] = x;
	list->last++;//list->last要+1

	return 0;
}

int DeleteSqlist(seqlist_t *list, int at)
{
	int i;
	if(list == NULL || at < 0 || (at > list->last))
		return -1;

	for(i = at + 1; i <= list->last;i++)
		list->data[i-1] = list->data[i];

	list->last--;

	return 0;
}