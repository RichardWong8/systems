default: shell.o shell_utils.o
	gcc shell.o shell_utils.o

shell.o: shell.c shell.h
	gcc -c shell.c

shell_utils.o: shell_utils.c shell.h
	gcc -c shell_utils.c

run:
	./a.out

test:
	./a.out < test_commands
