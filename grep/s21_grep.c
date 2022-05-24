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
    if (argc > 2) {
/* Read flags */
        flags grep_flags = {1, 1, 0, 0, 0, 0, 0, 0, 0};
        int i = check_flag(argv, argc, &grep_flags);
/* Prioritize flags */
//        priorities(&grep_flags);

/* Read pattern */
        char *pattern = argv[i++];
        printf("\nPattern = %s\n", pattern);

/* Output each file */
        while (i < argc && i != grep_flags.number) {
            grep_output(grep_flags, argv[i++], pattern);
        }
/* In case of no options called, throw error message */
    } else {
        fprintf(stderr, "usage: s21_grep [-eivclnhsfo] [file ...]");
    }

    return 0;
}

void grep_output(flags grep_flags, const char *filename, const char *pattern) {
    FILE *fp = fopen(filename, "r");

    if (fp) {
        regex_t regex;
        regcomp(&regex, pattern, 0);
        char *str = grep_getline(fp);
        int line_number = 1;
        while (str) {
            if (!regexec(&regex, str, 0, NULL, 0)) {
                printf("\n%d:Line = '%s'\n", line_number, str);
            }
            free(str);
            str = grep_getline(fp);
            line_number++;
        }
        regfree(&regex);
    } else if (!grep_flags.s_flag) {
/* Error output excluding -s flag (suppress error message) */
        fprintf(stderr, "grep: %s: %s\n", filename, strerror(errno));
    }
}

char *grep_getline(FILE *filepointer) {
    int c = 0, len = 1;
    char *line = calloc(len, sizeof(char));
/* Get strings with line till the end of file */
    while ((c = fgetc(filepointer)) != -1 && c != 10 && line) {
/* Temp output */
        putchar(c);
/* Get chars and relloc the size of array until \n */
        len++;
        char *temp_line = realloc(line, sizeof(char) * (len));
/* Realloc safely please! */
        if (temp_line) {
            line = temp_line;
            line[len - 2] = (char)c;
            line[len - 1] = '\0';
        } else {
            free(line);
            line = NULL;
        }
    }
/* End of file and empty line */
    if (c == -1 && len == 1) {
        free(line);
        line = NULL;
    }
    return line;
}
