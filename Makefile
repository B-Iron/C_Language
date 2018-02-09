#This is a makefile#
CC=gcc
CFLAGS=-I.
DEPS= myHeader.h
OBJ= main.o f1.o f2.o f3.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
Test:$(OBJ)
	gcc -o $@ $^ $(CFLAGS)
exec:
	./Test
.PHONY:clean

clean:
	del /f *.exe, *.o, *.d
