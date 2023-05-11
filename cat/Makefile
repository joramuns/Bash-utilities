CC=gcc
GCOV=gcc --coverage
CFLAGS=-std=c11 -Wall -Werror -Wextra -c
OFLAGS=-std=c11 -Wall -Werror -Wextra -o

clean:
	rm -rf *.o *.so *.gcda *.a *.gcno *.info test

s21_cat: cat_parser.o
	$(CC) $(CFLAGS) s21_cat.c
	$(CC) $(OFLAGS) s21_cat s21_cat.o cat_parser.o
	$(MAKE) clean

cat_parser.o:
	$(CC) $(CFLAGS) cat_parser.c

test: s21_cat
	./test_cat.sh

gcov_report: clean
	$(GCOV) $(CFLAGS) s21_cat.c cat_parser.c
	$(GCOV) $(OFLAGS) s21_cat s21_cat.o cat_parser.o
	./test_cat.sh
	lcov -t "test" -o test.info -c -d . --rc lcov_branch_coverage=1
	genhtml -o report test.info --rc lcov_branch_coverage=1
	$(MAKE) clean

debug:
	$(CC) -g $(CFLAGS) cat_parser.c
	$(CC) -g $(CFLAGS) s21_cat.c
	$(CC) -g $(OFLAGS) s21_cat s21_cat.o cat_parser.o
