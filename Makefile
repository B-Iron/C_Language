#This is a makefile#

#Syntax Rules#
CC=gcc
CFLAGS=-I.
DEPS= myHeader.h
OBJ= main.o f1.o f2.o f3.o
#--Start of Syntax BODY--#
#Dependacy for the header#
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
#Target makes all the files which is made possible by the Make Command#
Test:$(OBJ)
	gcc -o $@ $^ $(CFLAGS)
#--End of Syntax Body--#
#Execute Command runs the '.exe'#
exec:
	./Test
#.PHONY is use to non conflict the 'clean' command with an actual file#
.PHONY:clean
#Clean Command delets the files that you have made '.exe, .o, and .d'#
clean:
	del /f *.exe, *.o, *.d
#You have finished!#
