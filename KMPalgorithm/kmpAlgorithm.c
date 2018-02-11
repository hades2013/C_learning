// KMP算法
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void get_next(char *T,int next[])	//修正前的next数组 
{
	int i = 1,j = 0;
	next[0] = -1;
	next[1] = 0;
	int m = strlen(T);
	while(i<strlen(T)-1)
	{
		if(j == -1||T[j]==T[i])
		{
			++i;
			++j;
			next[i] = j;
		}
		else j = next[j];
	}
} 

void get_nextval(char *T,int nextval[])		//修正后的nextval数组
{
	int i = 1,j = 0;
	nextval[0] = -1;
	nextval[1] = 0;
	int m = strlen(T);
	while(i<strlen(T)-1)
	{
		if(j == -1||T[j]==T[i])
		{
			++i;
			++j;
			if(T[i]!=T[j]) nextval[i] = j;
			else nextval[i] = nextval[j];
		}
		else j = nextval[j];
	}
} 

int Index_kmp(char *S,char *T,int pos,int next[])	//逐项比较 
{
	int j = 0,i = pos,lens=strlen(S),lent=strlen(T);
	get_next(T,next);
	while(i<lens&&j<lent)
	{
		if(S[i]==T[j]||j==-1)
		{
			i++;j++;
		}
		else j = next[j];
	}
	if(j>=lent) return i-lent;
	else return -1;
}

int main()
{
	char *S="adbadabbaabadabbadada",*T="adabbadada";
	int m;
	int *next = (int *)malloc((strlen(T)+1)*sizeof(int));		//修正前的next数组
	int *nextval = (int *)malloc((strlen(T)+1)*sizeof(int));	//修正后的nextval数组

	get_next(T,next);
	printf("修正前next数组为：");
	for(m = 0;m<strlen(T);m++)
	{
		printf("%d ",next[m]+1);
	}

	get_nextval(T,nextval);
	printf("\n修正后的nextval数组为：");
	for(m=0;m<strlen(T);m++)
	{
		printf("%d ",nextval[m]+1);
	}


	int t = Index_kmp(S,T,0,nextval);
	if(t==-1)  	printf("\n无匹配项！\n");
	else
	{
		printf("\n在第%d项开始匹配成功\n",t+1);
	}
	return 0;
}