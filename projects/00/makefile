all: driver.o linked.o library.o
	gcc driver.o linked.o library.o

driver.o: driver.c linked.h
	gcc -c driver.c linked.h

linked.o: linked.c linked.h
	gcc -c linked.c linked.h

library.o: library.c library.h linked.h
	gcc -c library.c library.h linked.h

run:
	./a.out

