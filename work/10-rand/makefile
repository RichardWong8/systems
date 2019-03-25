default: driver.o randfile.o
	gcc driver.o randfile.o

driver.o: driver.c randfile.h
	gcc -c driver.c randfile.h

randfile.o: randfile.c randfile.h
	gcc -c randfile.c randfile.h

run:
	./a.out

clean:
	rm -f *~ *.o *.out *.exe