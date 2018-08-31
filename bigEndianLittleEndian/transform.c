#include <stdio.h>

int main()
{
    short int x;
    char x1,x2;
    x = 0x1122;
    x1 = ((char *)&x)[0];    //低地址
    x2 = ((char *)&x)[1];    //高地址
    printf("x1=%x\n",x1);
    printf("x2=%x\n",x2);
    return 0;
}
