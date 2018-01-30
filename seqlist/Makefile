
OBJS = seqlist.o main.o
CFLAGS = -c -g -Wall
CC = gcc

Test:$(OBJS)
	$(CC) -o Test -g $(OBJS)
main.o:main.c seqlist.h datatype.h
	$(CC) $(CFLAGS) main.c
seqlist.o:seqlist.c seqlist.h datatype.h
	$(CC) $(CFLAGS) seqlist.c

clean:
	rm -rf Test *.o