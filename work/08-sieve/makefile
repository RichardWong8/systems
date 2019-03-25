default: driver.o sieve.o
	gcc -o test driver.o sieve.o -lm

driver.o: driver.c sieve.h
	gcc -c driver.c sieve.h

sieve.o: sieve.c sieve.h
	gcc -c sieve.c sieve.h

run:
	./test

clean:
	rm -f *~ *.o *.out *.exe test
