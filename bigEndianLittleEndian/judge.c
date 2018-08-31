#include <stdio.h>


int main()
{
	int x = 1;
	char *p = (char *)&x;
	
	
	if(*p){
		printf("little!\n");
	}
	else {
		printf("large!\n");
	}
	return 0; 
}
