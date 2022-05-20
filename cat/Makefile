CC=gcc
GCOV=gcc --coverage
CFLAGS=-std=c11 -Wall -Werror -Wextra -c
OFLAGS=-std=c11 -Wall -Werror -Wextra -o

clean:
	rm -rf *.o *.so *.gcda *.a *.gcno *.info test sanit

s21_cat: check_flag.o
	$(CC) $(CFLAGS) s21_cat.c
	$(CC) $(OFLAGS) s21_cat s21_cat.o check_flag.o
	$(MAKE) clean

check_flag.o:
	$(CC) $(CFLAGS) ../common/check_flag.c

test: s21_cat
	../texts/test_cat.sh

gcov_report: clean
	$(GCOV) $(CFLAGS) s21_cat.c ../common/check_flag.c
	$(GCOV) $(OFLAGS) s21_cat s21_cat.o check_flag.o
	../texts/test_cat.sh
	lcov -t "test" -o test.info -c -d . --rc lcov_branch_coverage=1
	genhtml -o report test.info --rc lcov_branch_coverage=1
	$(MAKE) clean