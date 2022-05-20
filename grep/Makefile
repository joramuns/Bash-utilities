CC=gcc
GCOV=gcc --coverage
CFLAGS=-std=c11 -Wall -Werror -Wextra -c
OFLAGS=-std=c11 -Wall -Werror -Wextra -o

clean:
	rm -rf *.o *.so *.gcda *.a *.gcno *.info test sanit

s21_grep: check_flag.o
	$(CC) $(CFLAGS) s21_grep.c
	$(CC) $(OFLAGS) s21_grep s21_grep.o check_flag.o
	$(MAKE) clean

check_flag.o:
	$(CC) $(CFLAGS) ../common/check_flag.c

test: s21_grep
	./test_grep.sh
