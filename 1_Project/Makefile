#This is a makefile#

#Syntax Rules#
CC=gcc
CFLAGS=-I.
DEPS= myHeader.h
SOURCE= main.c f1.c f2.c f3.c
OBJ= $(SOURCE:.c=.o)
EXECUTABLE=Test
#--Start of Syntax BODY--#
#Executes all files with Make All Command even if there is no changes#
all: $(OBJ) $(EXECUTABLE)
#Dependacy for the header#
$(OBJ):$(SOURCE) $(DEPS)
	$(CC) -c $(SOURCE) $(CFLAGS)
#Target makes files with changes made possible by the Make Command#
$(EXECUTABLE):$(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
#--End of Syntax Body--#
#Execute Command runs the '.exe'#
exec:
	./Test
#.PHONY is use to non conflict the 'clean' command with an actual file#
.PHONY:clean
#Clean Command delets the files that you have made '.exe, .o, and .d'#
clean:
	rm -f *.exe *.o *.d
#You have finished!#
