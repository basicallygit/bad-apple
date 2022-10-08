.PHONY: all
all: main

main: main.o truncate.o
	cc -o badapple main.o truncate.o

main.o: main.c
	cc -c main.c -o main.o

truncate.o: truncate.c
	cc -c truncate.c -o truncate.o

.PHONY: clean
clean:
	rm -f main.o truncate.o
