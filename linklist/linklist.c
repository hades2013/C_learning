
#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

linklist_t CreateEmptyLinklist()
{
	linklist_t list;
	list = (linklist_t)malloc(sizeof(linknode_t));

	if (NULL != list) {
		list->next = NULL;
	}

	return list;
}

void DestroyLinklist(linklist_t list)
{
	if (NULL != list) {
		ClearLinklist(list);
		free(list);
	}
}

void ClearLinklist(linklist_t list)
{
	linknode_t *node; /* pointer to the node to be removed */
	if (NULL == list) return;

	while (NULL != list->next) {
		node = list->next;
		list->next = node->next;
		free(node);
	}
	return;
}

int LengthLinklist(linklist_t list)
{
	int len = 0;
	linknode_t *node; //iterate pointer

	if (NULL == list) return -1;

	node = list->next; // node points to the first data node
	while (NULL != node) {
		len++;
		node = node->next;
	}
	return len;
}

int EmptyLinklist(linklist_t list)
{
	if (NULL != list) {
		if (NULL == list->next) {
			return 1;
		} else {
			return 0;
		}
	} else {
		return -1;
	}
}

int GetLinklist(linklist_t list, int at, data_t *x)
{
	linknode_t *node;	/* used for iteration */
	int pos;		/* used for iteration and compare with */

	if (NULL == list) return -1;
	/* at must >= 0 */
	if (at < 0) return -1;
	/* start from the first element */
	node = list->next;
	pos = 0;
	while (NULL != node) {
		if (at == pos) {
			if (NULL != x) {
				*x = node->data;
			}
			return 0;			
		}
		/* move to the next */
		node = node->next;
		pos++;
	}
	return -1;
}



int SetLinklist(linklist_t list, int at, data_t x)
{
	linknode_t *node; /* used for iteration */
	int pos;
	int found = 0;

	if (!list) return -1;
	/* at must >= 0 */
	if (at < 0) return -1;
	/* start from the first element */
	node = list->next;
	pos = 0;
	while (NULL != node) {
		if (at == pos) { 
			found = 1; /* found the position */
			node->data = x;
			break;			
		}
		/* move to the next */
		node = node->next;
		pos++;
	}
	if (1 == found) {
		return 0;
	} else {
		return -1;
	}
}

int InsertLinklist(linklist_t list, int at, data_t x)
{
	/* 
	 * node_at and pos_at are used to locate the position of node_at.
	 * node_prev follows the node_at and always points to previous node 
	 *	of node_at.
	 * node_new is used to point to the new node to be inserted.
	 */
	linknode_t 	*node_prev, *node_at, *node_new;
	int		pos_at;
	int 		found = 0;

	if (NULL == list) return -1;

	/* at must >= 0 */
	if (at < 0) return -1;

	node_new = malloc(sizeof(linknode_t));
	if (NULL == node_new) {
		return -1;
	}
	node_new->data = x; /* assigned value */
	node_new->next = NULL;

	node_prev = list;
	node_at = list->next;
	pos_at = 0;
	while (NULL != node_at) {
		if (pos_at == at) {
			/* 
			 * found the node 'at'
			 */ 
			found = 1;
			break;			
		}
		/* move to the next pos_at */
		node_prev = node_at;
		node_at = node_at->next;
		pos_at++;
	}
	
	if (found) {
		/* insert */
		node_new->next = node_at;
		node_prev->next = node_new;
	} else {
		/* 
		 * If not found, means the provided "at"
		 * exceeds the upper limit of the list, just 
		 * append the new node to the end of the list.
		 */
		node_prev->next = node_new;
	}
	return 0;
}

int DeleteLinklist(linklist_t list, int at)
{
	/* 
	 * node_at and pos_at are used to locate the position of node_at.
	 * node_prev follows the node_at and always points to previous node 
	 *	of node_at.
	 */

	linknode_t 	*node_prev, *node_at;
	int		pos_at;
	int 		found = 0;

	if (!list) return -1;
	/* at must >= 0 */
	if (at < 0) return -1;

	node_prev = list;
	node_at = list->next;
	pos_at = 0; 

	while (NULL != node_at) {
		if (pos_at == at) {
			/* 
			 * found the node 'at'
			 */ 
			found = 1;
			break;			
		}
		/* move to the next pos_at */
		node_prev = node_at;
		node_at = node_at->next;
		pos_at++;
	}
	if (found) {
		/* remove */
		node_prev->next = node_at->next;
		free(node_at);
		return  0;
	} else {
		return -1;
	}
}

linklist_t ReverseLinklist(linklist_t list)
{
	linknode_t *node;	/* iterator */
	linknode_t *node_prev;	/* previous node of iterator */
	linknode_t *node_next;	/* next node of iterator, 
				 * used to backup next of iterator 
				 */
	if (NULL == list) return NULL;
	node_prev = NULL;
	node = list->next;
	while (NULL != node) {
		/*
		 * step1: backup node->next
		 * due to the next of iterator will be
		 * modified in step2
		 */
		node_next = node->next;
		/* 
		 * when iterator reaches the last node 
		 * of original list, make the list head
		 * point to the last node, so the original
		 * last one becomes the first one.
		 */

		if (NULL == node_next) {
			list->next = node;
		}

		/* 
		 * step2: reverse the linkage between nodes
		 * make the node pointer to the previous node,
		 * not the next node
		 */		
		node->next = node_prev;		
		/* 
		 * step3: move forward 
		 */

		node_prev = node;
		node = node_next;
	}
	return list;
}




