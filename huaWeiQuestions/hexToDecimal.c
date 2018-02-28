/*
* hex numbers to decimal 
* athor: hades 
* date: 2018-2-28 
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
    char str[100];
    int i=0,count,sum;
    while(gets(str))//用于多次输入
    {
        count=strlen(str);//计算字符串的长度
        sum=0;
        for(i=count-1;i>=0;i--)//从十六进制个位开始，每位都转换成十进制
        {
        if(str[i]>='0'&&str[i]<='9')//数字字符的转换
        {
            sum+=(str[i]-48)*pow(16,count-i-1);
        }
        else if(str[i]>='A'&&str[i]<='F')//字母字符的转换
        {
            sum+=(str[i]-55)*pow(16,count-i-1);
        }
        }
        printf("%d\n",sum);
    }
    return 0;
 }