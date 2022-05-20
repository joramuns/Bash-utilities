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
#include <regex.h>

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
        int c = 0, len = 0;
/* Get strings with line till the end of file */
        while (c != -1) {
            char *str = malloc(1 * sizeof(char));
            c = fgetc(fp);
            putchar(c);
/* Get chars and relloc the size of array until \n */
            while (c != 10 && c != -1) {
                if (c != 10) {
                    len++;
                    str = realloc(str, sizeof(char) * (len + 1));
                    str[len - 1] = (char)c;
                    str[len] = '\0';
                }
                c = fgetc(fp);
                putchar(c);
            }
/* Analyze the line and free it */
            if (len > 0) {
                printf("Line = %s\n", str);
            }
            free(str);
            str = NULL;
            len = 0;
        }
    } else {
/* Error output */
        fprintf(stderr, "grep: %s: %s\n", filename, strerror(errno));
    }
}
