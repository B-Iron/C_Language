CC=gcc
OBJ=obj
SRC=src
BIN=bin

-include *.d

## default target is to create diff executable
$(BIN)/diff: $(OBJ)/diff.o $(OBJ)/diff_utils.o
	-mkdir -p $(BIN)
	$(CC) -Wall -g -o $(BIN)/diff $^ -I$(SRC)

## compile all src to obj files
$(OBJ)/%.o: $(SRC)/%.c
	-mkdir -p $(OBJ)
	$(CC) -MMD -Wall -g -c -o $@ $< -I$(SRC)

.PHONY: test clean

test: $(OBJ)/diff_testdriver.o $(OBJ)/diff_utils.o
	-mkdir -p $(BIN)
	$(CC) -Wall -g -o $(BIN)/test $^ -I$(SRC)
	$(BIN)/test

clean: 
	rm -f $(BIN)/* $(OBJ)/*
