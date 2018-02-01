#include <stdio.h>
#include <assert.h>

char * strcpyA(char * strDest, const char *strSrc)
{
	assert(strSrc != NULL);
	assert(strDest != NULL);	
	int i; 
	char *address = strDest;
	for(i =0; strSrc[i] != '\0'; i++)
		strDest[i] = strSrc[i];
	strDest[i] = '\0';

	return address;
}

char *strcpyB(char *strDest, const char *strSrc)
{
	assert((strSrc != NULL)&&(strDest != NULL));
	char *address = strDest;
	while((*strDest++ = *strSrc++)!='\0');
	return address;
}

int main(int argc, char const *argv[])
{
	char *str = "hello world!";
	char buf[32] = {0};
	strcpyB(buf, str);
	printf("strcpy : %s\n", buf);
	return 0;
}