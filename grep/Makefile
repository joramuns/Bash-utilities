CC=gcc
GCOV=gcc --coverage
CFLAGS=-std=c11 -Wall -Werror -Wextra -c
OFLAGS=-std=c11 -Wall -Werror -Wextra -o

clean:
	rm -rf *.o *.so *.gcda *.a *.gcno *.info test

s21_grep: grep_parser.o
	$(CC) $(CFLAGS) s21_grep.c
	$(CC) $(OFLAGS) s21_grep s21_grep.o grep_parser.o
	$(MAKE) clean

grep_parser.o:
	$(CC) $(CFLAGS) grep_parser.c

test: s21_grep
	./test_grep.sh

gcov_report: clean
	$(GCOV) $(CFLAGS) s21_grep.c grep_parser.c
	$(GCOV) $(OFLAGS) s21_grep s21_grep.o grep_parser.o
	./test_grep.sh
	lcov -t "test" -o test.info -c -d . --rc lcov_branch_coverage=1
	genhtml -o report test.info --rc lcov_branch_coverage=1
	$(MAKE) clean

debug:
	$(CC) -g $(CFLAGS) grep_parser.c
	$(CC) -g $(CFLAGS) s21_grep.c
	$(CC) -g $(OFLAGS) s21_grep s21_grep.o grep_parser.o
