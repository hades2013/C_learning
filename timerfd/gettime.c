/*
* get time test 
* athor: hades
* email: hades2013ac@gmail.com
* date: 2018-3-8
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/times.h>
#include <time.h>
#include <sys/time.h>

/*
精确度比较:
以下是各种精确度的类型转换:
1秒=1000毫秒(ms), 1毫秒=1/1000秒(s)；
1秒=1000000 微秒(μs), 1微秒=1/1000000秒(s)；
1秒=1000000000 纳秒(ns),1纳秒=1/1000000000秒(s)；

clock()函数的精确度是10毫秒(ms)
times()函数的精确度是10毫秒(ms)
gettimofday()函数的精确度是微秒(μs)
clock_gettime()函数的计量单位为十亿分之一，也就是纳秒(ns)

clock_t times(struct tms *buf);
struct tms{
 clock_t tms_utime;   //记录的是进程执行用户代码的时间
 clock_t tms_stime;    //记录的是进程执行内核代码的时间.
 clock_t tms_cutime;    //记录的是子进程执行用户代码的时间.
 clock_t tms_cstime;     //记录的是子进程执行内核代码的时间.
};

gettimeofday()可以获得当前系统的时间,是一个绝对值
int gettimeofday ( struct timeval * tv , struct timezone * tz );
struct timeval 
{
    time_t      tv_sec;    
    suseconds_t tv_usec;   
};
*/

#define WAIT for(i=0;i<298765432;i++);
#define MILLION    1000000

int main(int argc, char const *argv[])
{
	int i;
    long ttt;
    clock_t s,e;
    struct tms aaa;

    s=clock();
    WAIT;
    e=clock();
    printf("clock time : %.12f\n",(e-s)/(double)CLOCKS_PER_SEC);

    long tps = sysconf(_SC_CLK_TCK);
    s=times(&aaa);
    WAIT;
    e=times(&aaa);
    printf("times time : %.12f\n",(e-s)/(double)tps);

    struct timeval tvs,tve;
    gettimeofday(&tvs,NULL);
    WAIT;
    gettimeofday(&tve,NULL);
    double span = tve.tv_sec-tvs.tv_sec + (tve.tv_usec-tvs.tv_usec)/1000000.0;
    printf("gettimeofday time: %.12f\n",span);

    struct timespec tpstart;
    struct timespec tpend;

    clock_gettime(CLOCK_REALTIME, &tpstart);
    WAIT;
    clock_gettime(CLOCK_REALTIME, &tpend);
    double timedif = (tpend.tv_sec-tpstart.tv_sec)+(tpend.tv_nsec-tpstart.tv_nsec)/1000000000.0;
    printf("clock_gettime time: %.12f\n", timedif);

    return EXIT_SUCCESS;
}