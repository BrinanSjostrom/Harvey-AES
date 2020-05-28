CC=gcc
CFLAGS=-g
BIN=/usr/bin
EXE=harvey
SRC=main.c

make: main.c
	$(CC) -o $(EXE) $(SRC) $(CFLAGS)
	mv $(EXE) $(BIN)
