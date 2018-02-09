<<<<<<< HEAD
#This is a makefile
=======
Test: main.c f1.c f2.c f3.c
	gcc -o Test main.c f1.c f2.c f3.c -I

CC=gcc
CFLAGS=-I

Test: main.o f1.o f2.o f3.o
	    $(CC) -o Test main.o f1.o f2.o f3.o -I.

CC=gcc
CFLAGS=-I.
DEPS = myHeader.h

%.o: %.c $(DEPS)
			$(CC) -c -o $@ $< $(CFLAGS)

Test: main.o f1.o f2.o f3.o
				gcc -o Test main.o f1.o f2.o f3.o -I.
>>>>>>> fec628ca431b6398199aae59fc6d1bac797fd7ed


CC=gcc
CFLAGS=-I.
<<<<<<< HEAD
OBJ=main.o f1.o f2.o f3.o
DEPS=myHeader.h

/%.o: %.c $(DEPS)
			$(CC) -c -o $@ $< $(CFLAGS)

Test: $(OBJ)
			gcc -o $@ $^ $(CFLAGS)

exec:
		./Test

.PHONY:clean

clean:
		del /f *.exe, *.o, *.d, *., *~
=======
DEPS = myHeader.h
OBJ = main.o f1.o f2.o f3.o

%.o: %.c $(DEPS)
			$(CC) -c -o $@ $< $(CFLAGS)

Test: $(OBJ)
				gcc -o $@ $^ $(CFLAGS)


IDIR =../include
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=obj
LDIR =../lib

LIBS=-lm

_DEPS = myHeader.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o f1.o f2.o f3.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
			$(CC) -c -o $@ $< $(CFLAGS)

hellomake: $(OBJ)
				gcc -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
				rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
>>>>>>> fec628ca431b6398199aae59fc6d1bac797fd7ed
