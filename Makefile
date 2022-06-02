CC=gcc
GCOV=gcc --coverage
CFLAGS=-std=c11 -Wall -Werror -Wextra -c
OFLAGS=-std=c11 -Wall -Werror -Wextra -o

clean:
	rm -rf *.o *.so *.gcda *.a *.gcno *.info ./cat/s21_cat ./grep/s21_grep

s21_cat:
	make -C cat/ s21_cat

s21_grep:
	make -C grep/ s21_grep

test:
	make -C grep/ test
	make -C cat/ test

gcov_report: clean
	$(GCOV) $(CFLAGS) ./grep/s21_grep.c ./grep/grep_parser.c
	$(GCOV) $(OFLAGS) ./grep/s21_grep s21_grep.o grep_parser.o
	make -C grep/ test
	lcov -t "test_grep" -o test_grep.info -c -d . --rc lcov_branch_coverage=1
	$(GCOV) $(CFLAGS) ./cat/s21_cat.c ./cat/cat_parser.c
	$(GCOV) $(OFLAGS) ./cat/s21_cat s21_cat.o cat_parser.o
	make -C cat/ test
	lcov -t "test_cat" -o test_cat.info -c -d . --rc lcov_branch_coverage=1
	genhtml -o report test_grep.info test_cat.info --rc lcov_branch_coverage=1
	$(MAKE) clean

