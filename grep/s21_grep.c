//
//  s21_grep.c
//  S21 cat and grep
//
//  Created by Joramun Sasin on 5/20/22.
//

#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "s21_grep.h"

int main(int argc, char *argv[]) {
    if (argc > 1) {
/* Read flags */
        flags grep_flags = {1, 1, 0, 0, 0, 0, 0, 0, 0};
        int i = check_flag(argv, argc, &grep_flags);
/* Prioritize flags */
//        priorities(&grep_flags);

/* Output each file */
        while (i <= argc && i != grep_flags.number) {
            grep_output(grep_flags, argv[i - 1]);
            i++;
        }
/* In case of no options called, throw error message */
    } else {
        fprintf(stderr, "usage: s21_grep [-eivclnhsfo] [file ...]");
    }

    return 0;
}

void grep_output(flags grep_flags, const char *filename) {
    FILE *fp = fopen(filename, "r");

    if (fp) {
        printf("OK\n");
    } else {
/* Error output */
        fprintf(stderr, "cat: %s: %s\n", filename, strerror(errno));
    }
}
