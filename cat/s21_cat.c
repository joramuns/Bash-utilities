//
//  s21_cat.c
//  S21 cat and grep
//
//  Created by Joramun Sasin on 5/11/22.
//
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "s21_cat.h"

int main(int argc, char *argv[]) {
    if (argc > 1) {
/* Read flags */
        flags cat_flags = {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0};
        check_flag(argv, argc, &cat_flags);
/* Prioritize flags */
        priorities(&cat_flags);

/* Output each file */
        while (cat_flags.pars_pos < argc) {
            cat_output(cat_flags, argv[cat_flags.pars_pos]);
            cat_flags.pars_pos++;
        }
/* In case of no options called, throw error message */
    } else {
        fprintf(stderr, "usage: s21_cat [-benstuv] [file ...]");
    }

    return 0;
}

void cat_output(flags cat_flags, const char *filename) {
    FILE *fp = fopen(filename, "r");
/*
 Initialization of vars :
 c - for character
 l_counter - counts number of lines
 nl_counter - counts new-line characters
 */
    if (fp) {
        int l_counter = 1, nl_counter = 0;
        do {
            int c = fgetc(fp);
/* First line numeration, -n or -b flag */
            if ((cat_flags.n_flag || (cat_flags.b_flag && c != '\n')) && l_counter == 1 && c != -1) {
                printf("%6d\t", l_counter++);
            }
/* Cut new-line signs and count it */
            while (c == '\n') {
                c = fgetc(fp);
                nl_counter++;
            }
/* Output of new-line characters depends on -s, -n, -b flags */
            if (nl_counter) {
                new_line(cat_flags, &nl_counter, &l_counter, c);
            }
            if (feof(fp)) {
                break;
            }
/* Check non-readable chars in accordance with flags */
            if (c < 32 || c > 126) {
                cat_np_output(cat_flags, &c);
            }
            putchar(c);
        } while (!feof(fp));
        fclose(fp);
    } else {
/* Error output */
        fprintf(stderr, "cat: %s: %s\n", filename, strerror(errno));
    }
}

void new_line(flags flags, int *counter, int *line, int c) {
/* Reduce the number of empty lines in case of -s flag */
    if (flags.s_flag && *counter > 2) {
        *counter = 2;
    }
    while (*counter > 0) {
/* -e flag outputs $ in the end of line */
        if (flags.e_flag) {
            putchar('$');
        }
        putchar('\n');
/* 6-wide block for line counter in case of -n or -b flag */
        if (flags.n_flag || (flags.b_flag && *counter == 1)) {
            if (!(c == -1 && *counter == 1)) {
                printf("%6d\t", (*line)++);
            }
        }
        (*counter)--;
    }
}

void cat_np_output(flags flags, int *c) {
/* Print non-printable characters in format "^@" */
    if (flags.v_flag && *c != '\t') {
        if (*c < 32) {
            putchar('^');
            *c += 64;
        } else if (*c == 127) {
            putchar('^');
            *c -= 64;
        } else if (*c > 127 && *c < 160) {
            putchar('M');
            putchar('-');
            putchar('^');
            *c -= 64;
        }
    }
/* Print "^I" instead of tabs in case of -T flag */
    if (flags.t_flag && *c == '\t') {
        putchar('^');
        *c += 64;
    }
}

void priorities(flags *flags) {
/* -b flag > -n flag */
    if (flags->b_flag) {
        flags->n_flag = 0;
    }
}
