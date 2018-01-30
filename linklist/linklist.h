#ifndef _LNK_LIST_H_
#define _LNK_LIST_H_

typedef int data_t;

typedef struct node_t {
	data_t data;
	struct node_t *next;
} linknode_t, *linklist_t;

linklist_t CreateEmptyLinklist();

void DestroyLinklist(linklist_t list);

void ClearLinklist(linklist_t list);

int EmptyLinklist(linklist_t list);

int LengthLinklist(linklist_t list);

int GetLinklist(linklist_t list, int at, data_t *x);

int SetLinklist(linklist_t list, int at, data_t x);

int InsertLinklist(linklist_t list, int at, data_t x);

int DeleteLinklist(linklist_t list, int at);

linklist_t ReverseLinklist(linklist_t list);

#endif /* _LNK_LIST_H_ */