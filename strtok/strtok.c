#include <stdio.h>

char *strtokA(char *str, char *delim)
{
	static char *src = NULL; 
	const char *indelim=delim; 
	int flag =1, index=0; 
	char *temp =NULL;
	if(str==NULL)
		str=src; 
	for(; *str; str++){
		 	delim = indelim; 
		 	for(; *delim; delim++){
				if(*str==*delim){
					*str = NULL;
					index =1; 
					break;
				}	
			}
		if(*str!=NULL&&flag==1){
			temp=str; 
			flag =0; 
		}
		if(*str!=NULL && flag == 0 && index==1){
			src =str; 
			return temp;
		}
	}
	src = str; 
	return temp; 
}

int main(int argc, char const *argv[])
{
	char s[] = "ab-cd : ef;gh :i-jkl;mnop;qrs-tu: vwx-y;z";
	char *delim = "-:";
	char *p; 
	//printf("%s\n", strtok(s, delim));
	//while((p =strtok(NULL, delim)))
	printf("%s\n", strtokA(s, delim));
	while((p =strtokA(NULL, delim)))
		printf("%s",p );
	printf("\n");
	return 0;
}
