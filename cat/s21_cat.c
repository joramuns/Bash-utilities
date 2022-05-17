//
//  s21_cat.c
//  S21 cat and grep
//
//  Created by Joramun Sasin on 5/11/22.
//
//#include <stdarg.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "s21_cat.h"
#include "check_flag.h"


int main(int argc, char *argv[]) {
    printf("%", stderr);
    /* Reading flags */
    int i = 1;
    flags cat_flags = {1, 0, 0, 0, 0, 0, 0, 0, 0};
    while (cat_flags.flag_true == 1 && i < argc) {
        check_flag(argv[i++], &cat_flags);
    }
    i--;

    /* Output each file */
    while (i < argc) {
        output (cat_flags, argv[i]);
        i++;
//        if (i != argc) {
//            putchar('\n');
//        }
    }

    return 0;
}

void output(flags cat_flags, const char *filename) {
    FILE *fp = fopen(filename, "r");

    int c = 0, l_counter = 1, nl_counter = 0;
    if (fp) {
        do {
            if ((cat_flags.n_flag || cat_flags.b_flag) && l_counter == 1) {
                printf("     %d  ", l_counter++);
            }
            c = fgetc(fp);
            while (c == '\n') {
                c = fgetc(fp);
                nl_counter++;
            }
            if (nl_counter) {
                new_line(cat_flags, &nl_counter, &l_counter);
            }
            if (feof(fp)) {
                break;
            }
            putchar(c);
         } while (!feof(fp));
    } else {
        printf("cat: %s: %s\n", filename, strerror(errno));
    }
    fclose(fp);
}

void new_line(flags flags, int *counter, int *line) {
    if (flags.s_flag && *counter > 2) {
        *counter = 2;
    }
    while (*counter > 0) {
        if (flags.e_flag) {
            putchar('$');
        }
        putchar('\n');
        if (flags.n_flag || (flags.b_flag && *counter == 1)) {
            printf("     %d  ", (*line)++);
        }
        (*counter)--;
    }
}
