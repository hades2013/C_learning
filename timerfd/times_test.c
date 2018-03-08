/*
* get time test 
* athor: hades
* email: hades2013ac@gmail.com
* date: 2018-3-8
*/

#include <sys/times.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

/*
clock_t times(struct tms *buf);
struct tms{
 clock_t tms_utime;   //记录的是进程执行用户代码的时间
 clock_t tms_stime;    //记录的是进程执行内核代码的时间.
 clock_t tms_cutime;    //记录的是子进程执行用户代码的时间.
 clock_t tms_cstime;     //记录的是子进程执行内核代码的时间.
};

内核时钟
sysconf(_SC_CLK_TCK)是GNU标准库的clock_t频率.
它的定义位置在:/usr/include/asm/param.h
*/
static void do_cmd(char *);
static void pr_times(clock_t, struct tms *, struct tms *);

int main(int argc, char *argv[])
{
    int i;
    for(i=1; argv[i]!=NULL; i++){
        do_cmd(argv[i]);
    }
    exit(1);
}
static void do_cmd(char *cmd)
{
    struct tms tmsstart, tmsend;
    clock_t start, end;
    int status;
    if((start=times(&tmsstart))== -1)
        puts("times error");
   if((status=system(cmd))<0)
        puts("system error");
    if((end=times(&tmsend))== -1)
        puts("times error");
    pr_times(end-start, &tmsstart, &tmsend);
    exit(0);
}
static void pr_times(clock_t real, struct tms *tmsstart, struct tms *tmsend)
{
    static long clktck=0;
    if(0 == clktck)
        if((clktck=sysconf(_SC_CLK_TCK))<0)
                 puts("sysconf err");
    printf("real:%7.2f\n", real/(double)clktck);
    printf("user-cpu:%7.2f\n", (tmsend->tms_utime - tmsstart->tms_utime)/(double)clktck);
    printf("system-cpu:%7.2f\n", (tmsend->tms_stime - tmsstart->tms_stime)/(double)clktck);
    printf("child-user-cpu:%7.2f\n", (tmsend->tms_cutime - tmsstart->tms_cutime)/(double)clktck);
    printf("child-system-cpu:%7.2f\n", (tmsend->tms_cstime - tmsstart->tms_cstime)/(double)clktck);
}

/*
the result: 
$ ./times_test "dd if=/dev/zero of=/dev/null bs=1M count=10000"
10000+0 records in
10000+0 records out
10485760000 bytes (10 GB) copied, 0.594754 s, 17.6 GB/s
real:   0.68
user-cpu:   0.00
system-cpu:   0.00
child-user-cpu:   0.00
child-system-cpu:   0.55
*/