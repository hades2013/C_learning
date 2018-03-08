/*
* clock_gettime() test 
* athor: hades
* email: hades2013ac@gmail.com
* date: 2018-3-6
*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/*
* long sys_clock_gettime (clockid_t which_clock, struct timespec *tp);
* CLOCK_REALTIME:系统实时时间,随系统实时时间改变而改变,即从UTC1970-1-1 0:0:0开始计时,中间时刻如果系统时间被用户该成其他,则对应的时间相应改变
* CLOCK_MONOTONIC:从系统启动这一刻起开始计时,不受系统时间被用户改变的影响
* CLOCK_PROCESS_CPUTIME_ID:本进程到当前代码系统CPU花费的时间
* CLOCK_THREAD_CPUTIME_ID:本线程到当前代码系统CPU花费的时间
*
*/
#if 0 
struct timespec {
	time_t tv_sec;                /* Seconds */
	long   tv_nsec;               /* Nanoseconds */
};


struct itimerspec {
	struct timespec it_interval;  /* Interval for periodic timer */
	struct timespec it_value;     /* Initial expiration */
};
#endif 

int main(int argc, char const *argv[])
{
	struct timespec time = {0, 0}; 
	clock_gettime(CLOCK_REALTIME, &time); 
	printf("CLOCK_REALTIME: %d , %d\n", time.tv_sec, time.tv_nsec);
	clock_gettime(CLOCK_MONOTONIC, &time);
	printf("CLOCK_MONOTONIC: %d , %d\n", time.tv_sec, time.tv_nsec);
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time);
	printf("CLOCK_PROCESS_CPUTIME_ID: %d , %d\n", time.tv_sec, time.tv_nsec);
	clock_gettime(CLOCK_THREAD_CPUTIME_ID, &time);
	printf("CLOCK_THREAD_CPUTIME_ID: %d , %d\n", time.tv_sec, time.tv_nsec);

	printf("\n %d \n", times(NULL));
	sleep(1);
	return 0;
}