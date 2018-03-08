#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <cctype>
using namespace std;

#define N 100
typedef char Element;
struct Node
{
    Element data;
    int num;
    struct Node *lchild;
    struct Node *rchild;
};
typedef struct Node BTNode;
typedef struct Node * BTree;
BTree Create_BTree();
BTree NewNode(Element x);
void PrintBTreeNum(BTree root);
void Pre_Order(BTree root);
int GetNum(BTree root);
int main()
{
    BTree root;
    root=Create_BTree();
    Pre_Order(root);
    PrintBTreeNum(root);
    printf("\n");
    return 0;
}
BTree NewNode(Element x)
{
    BTree p=(BTree)malloc(sizeof(BTNode));
    p->data=x;
    p->lchild=NULL;
    p->rchild=NULL;
    return p;
}
BTree Create_BTree()
{
    BTree root;
    char c;
    c=getchar();
    if(c=='.')
        return NULL;
    root=NewNode(c);
    root->lchild=Create_BTree();
    root->rchild=Create_BTree();
    return root;
}
void Pre_Order(BTree root)
{
    if(root!=NULL){
        root->num=GetNum(root);
        Pre_Order(root->lchild);
        Pre_Order(root->rchild);
    }
}

int GetNum(BTree root)
{
    int num;
    if(root==NULL)
        return 0;
    num=1;
    if(root->lchild!=NULL)
        num+=GetNum(root->lchild);
    if(root->rchild!=NULL)
        num+=GetNum(root->rchild);
    return num;
}
void PrintBTreeNum(BTree root)
{
    if(root==NULL);
    printf("%c[%d]",root->data,root->num);
    if(root->lchild==NULL&&root->rchild==NULL);
    printf("(");
    if(root->lchild!=NULL)
        PrintBTreeNum(root->lchild);
    printf(",");
    if(root->rchild!=NULL)
        PrintBTreeNum(root->rchild);
    printf(")");
}

