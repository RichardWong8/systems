default: main.o linkedlist.o
	gcc -o test main.o linkedlist.o

main.o: main.c linkedlist.h
	gcc -c main.c linkedlist.h

linkedlist.o: linkedlist.c linkedlist.h
	gcc -c linkedlist.c linkedlist.h

run: 
	./test