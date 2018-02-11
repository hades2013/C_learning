
#include<stdio.h>
void schedule(int m,int n,int *t){
	//初始化
	int i,j,k,max=0;
	int d[100],s[100][100],count[100];
	for(i=0;i<m;i++){
		d[i]=0;
		for(j=0;j<n;j++){
			s[i][j]=-1;//-1代表不执行任何任务，不与第0号任务混淆
		}
	}
	//分配前m个任务
	//必然是每个机器先分别接受1个任务
	for(i=0;i<m;i++){
		s[i][0]=i;
		d[i]=d[i]+t[i];
		count[i]=1;
	}
	//之后判断哪个机器任务耗时最少，让其接受任务
	//尽可能地并行，平均分配任务
	for(i=m;i<n;i++){
		int min=d[0];
		k=0;
		for(j=1;j<m;j++){//确定空闲机器，实质是在求当期任务总时间最少的机器
			if(min>d[j]){
				min=d[j];
				k=j;//机器k空闲
			}
		}
		s[k][count[k]]=i;//在机器k的执行队列添加第i号任务
		count[k]=count[k]+1;//机器k的任务数+1
		d[k]=d[k]+t[i];//机器k的任务执行时间+t[i]，也就是+第i号任务的耗时		
	}
	
	for(i=0;i<m;i++){//确定完成所有任务需要的时间，实质是求分配完所有任务之后，耗时最多的机器
		if(max<d[i]){
			max=d[i];
		}			
	}
	printf("完成所有任务需要的时间：%d\n",max);
	printf("各个机器执行的耗时一览：\n");
	for(i=0;i<m;i++){
		printf("%d:",i);
		for(j=0;j<n;j++){
			if(s[i][j]==-1){
				break;
			}
			printf("%d\t",t[s[i][j]]);
		}
		printf("\n");
	}
}
void main(){//测试用例
	int time[7]={16,14,6,5,4,3,2};
	schedule(3,7,time);	
}