/*
* clock_gettime() test 
* athor: hades
* email: hades2013ac@gmail.com
* date: 2018-3-6
*/
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/select.h>
#include <sys/timerfd.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <signal.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/un.h>
// test, that select () with timeout={0,0} exits immediately
static void test_select_null_null(void)
{
  // create timer to check whether a followixng call to select() blocks
  int timerfd = timerfd_create(CLOCK_MONOTONIC, TFD_NONBLOCK | TFD_CLOEXEC);
  //TEST_ASSERT_UNEQUAL (timerfd, -1);

  // arm timer to fire in 5 seconds
  struct itimerspec new_value;
  new_value.it_value.tv_sec = 6;
  new_value.it_value.tv_nsec = 0;
  new_value.it_interval.tv_sec = 6;
  new_value.it_interval.tv_nsec = 0;
  int status = timerfd_settime(timerfd, 0, &new_value, 0);
  //TEST_ASSERT_EQUAL (status, 0);
  // prepare fd_set to select() on it
  fd_set fds;
  FD_ZERO(&fds);
  FD_SET(timerfd, &fds);
  // doing select() with timeout = {0, 0}

  struct timeval timeout ={ 0, 0 };
  int nfds;
  printf("test-select end------start.\n ");
  nfds = select(timerfd + 1, &fds, NULL, NULL, 0);//&timeout
  printf("test-select end------end.%d\n ",nfds);
  // no fds must be ready and select() should complete without errors
  //TEST_ASSERT_EQUAL (nfds, 0);
  timeout.tv_sec = 1;
  timeout.tv_usec = 0;

  // select(2):
  // Some  code  calls  select() with all three sets empty, nfds zero, and a
  // non-NULL timeout as a fairly portable way to sleep with subsecond
  // precision.
  nfds = select(0, &fds, NULL, NULL, &timeout);

  // no fds must be ready and select() should complete without errors
  //TEST_ASSERT_EQUAL (nfds, 0);
  close(timerfd);
}
// test, that select () returns correctly if there is two fds for reading and only one available

// solved with else mustWait=false
static void test_select_rfds(void)
{
  // create timer to check whether a following call to select() blocks
  int timerfd = timerfd_create(CLOCK_MONOTONIC, 0);
  //TEST_ASSERT_UNEQUAL (timerfd, -1);
  // arm timer to fire in 5 seconds
  struct itimerspec new_value;
  new_value.it_value.tv_sec = 2;
  new_value.it_value.tv_nsec = 0;
  new_value.it_interval.tv_sec = 2;
  new_value.it_interval.tv_nsec = 0;
  int status = timerfd_settime(timerfd, 0, &new_value, 0);

  //TEST_ASSERT_EQUAL (status, 0);

  int filefd = open("X1", O_CREAT | O_TRUNC | O_RDWR, S_IRWXU);
  // prepare fd_set to select() on it
  fd_set fds;
  FD_ZERO(&fds);
  FD_SET(timerfd, &fds);
  FD_SET(filefd, &fds);

  // doing select() with timeout = {0, 0}
  struct timeval timeout = { 6, 0};
  int nfds = select(timerfd > filefd ? timerfd + 1 : filefd + 1, &fds, NULL, NULL, &timeout);
  close(timerfd);
  close(filefd);
}
#if 0
int main(int argc, char *argv[])
{
  signal(SIGPIPE, SIG_IGN);

  if (1 < 2)
  {
    test_select_null_null();
    test_select_rfds();
  }


   printf("test-select end.\n ");
   fflush(stdout);
  fflush(stderr);
  sleep(1);
  return 0;
}
#endif
//这里只看test_select_null_null(void)这个函数就可以了，下面的基本都类似。
//自己也写了一个类似的：
int bQuit = 1;
int curTimerValue = 0;
int delayValue = 0;
 
void Close()
{
   bQuit = 0;
}
void SetValue()
{
   delayValue = curTimerValue ;
}
void CloseTimer(int timerfd)
{
  close(timerfd);
}
void *ThreadProc(void*param)
{
   //clear data pointer
   //delete *p
   //memset(0,p,len);
   while (bQuit)
   {
     curTimerValue++;
     int delay = curTimerValue - delayValue;
     if (delay > 10 )
     {
        //delete *p
     }
   }
}
void Init()
{
   pthread_t id;
   if (-1 == pthread_create(&id,NULL,ThreadProc,NULL))
   {
         //error
   }
}
void CreateTimer (struct itimerspec new_value)
{
  int timerfd = timerfd_create (CLOCK_MONOTONIC, 0);
  int status = timerfd_settime (timerfd, 0, &new_value, 0);
  fd_set fds;
  FD_ZERO (&fds);
  FD_SET (timerfd, &fds);
  struct timeval timeout ={ 0, 0 };
  int nfds = select (timerfd + 1, &fds, NULL, NULL, &timeout);
  timeout.tv_sec = 1;
  timeout.tv_usec = 0;
  nfds = select (0, &fds, NULL, NULL, &timeout);
  CloseTimer (timerfd);
}
int main(int argc,char*argv[])
{
  struct itimerspec new_value;
  new_value.it_value.tv_sec = 5;
  new_value.it_value.tv_nsec = 0;
  new_value.it_interval.tv_sec = 0;
  new_value.it_interval.tv_nsec = 0;
  CreateTimer(new_value);
}
