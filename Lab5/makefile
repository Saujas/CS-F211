CC = gcc
CFLAGS = -lm

compile: rec.o
	$(CC) rec.o -o run $(CFLAGS)

run: compile
	./run

rec.o: rec.c file.h
	$(CC) -c rec.c $(CFLAGS)
