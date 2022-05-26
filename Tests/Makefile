CC=gcc -g
GCOV=gcc --coverage
CFLAGS=-std=c11 -Wall -Werror -Wextra -c
OFLAGS=-std=c11 -Wall -Werror -Wextra -o

clean:
	rm -rf *.o *.so *.gcda *.a *.gcno test *.info sanit

test1: nodes.o
	$(CC) $(CFLAGS) test_nodes.c -lcheck
	$(CC) $(OFLAGS) test test_nodes.o nodes.o -lcheck
	./test

nodes.o:
	$(CC) $(CFLAGS) ../common/nodes.c

