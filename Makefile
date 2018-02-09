#This is a makefile#
CC=gcc
CFLAGS=-I.
DEPS= myHeader.h
OBJ= main.o f1.o f2.o f3.o
#Syntax BODY#
#Dependacy command for the header#
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
#Makes all the files#
Test:$(OBJ)
	gcc -o $@ $^ $(CFLAGS)
#Execute command runs the '.exe'#
exec:
	./Test
#.PHONE is use to non conflict the 'clean' command with an actual file#
.PHONY:clean
#Clean Command#
clean:
	del /f *.exe, *.o, *.d
#You have finished!#
