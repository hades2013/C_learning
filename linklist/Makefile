
OBJS = linklist.o main.o
CFLAGS = -c -g -Wall
CC = gcc

Test:$(OBJS)
	$(CC) -o Test -g $(OBJS)
main.o:main.c linklist.h 
	$(CC) $(CFLAGS) main.c
seqlist.o:linklist.c linklist.h
	$(CC) $(CFLAGS) linklist.c linklist.h

clean:
	rm -rf Test *.o