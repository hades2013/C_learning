#include <stdio.h> 

int main(int argc, char const *argv[])
{
	int a=2;  
    int b=3;  
    int i=1;  
  
    printf("%d\n",a+++b);  
    printf("%d,%d\n",a,b);  
    a=2;b=3;  
    printf("%d\n",a+++(++b));  
    printf("%d,%d\n",a,b);  
    a=2;b=3;  
    printf("%d\n",i);  
    printf("%d\n",++i+(++i)+(++i));  
    printf("%d\n",i);  
    i=1;  
    printf("%d\n",++i+(++i)+(++i)+(++i));  
    printf("%d\n",i);  
    i=1;  
    printf("%d\n",++i+(++i)+((++i)+(++i)));  
    printf("%d\n",i);  
  
	return 0;
}