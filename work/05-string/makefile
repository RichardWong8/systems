all: string.o func.o
	gcc string.o func.o
string.o: string.c func.h
	gcc -c string.c
func.o: func.c
	gcc -c func.c
run:
	./a.out
