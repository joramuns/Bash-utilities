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
        flags grep_flags = {2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        check_flag(argv, argc, &grep_flags);
        grep_flags.pars_pos = 1;  // temp null
/* Prioritize flags */
//        priorities(&grep_flags);
/* Read pattern */
        while (*argv[grep_flags.pars_pos] == '-' && grep_flags.pars_pos < argc) {
            grep_flags.pars_pos++;
        }
        char *pattern = argv[grep_flags.pars_pos];
        grep_flags.pars_pos++;

/* Output each file */
        while (grep_flags.pars_pos < argc) {
            if (*argv[grep_flags.pars_pos] == '-') {
                grep_flags.pars_pos++;
            } else {
                grep_output(grep_flags, argv[grep_flags.pars_pos++], pattern);
            }
        }
/* In case of no options called, throw error message */
    } else {
        fprintf(stderr, "usage: s21_grep [-eivclnhsfo] [pattern] [file ...]");
    }

    return 0;
}

void grep_output(flags grep_flags, const char *filename, const char *pattern) {
    FILE *fp = fopen(filename, "r");
    if (fp) {
        /* Used for sensibility in pattern case */
        int reg_option = grep_flags.i_flag ? REG_ICASE : 0;
        regex_t regex;
        regcomp(&regex, pattern, reg_option);
        char *str = grep_getline(fp);
        int line_number = 1, line_count = 0;
        while (str) {
/* Print either matched line (if no -v flag) or other than matched line */
            if (regexec(&regex, str, 0, NULL, 0) == grep_flags.v_flag) {
/* With -n flag a number of line will be output */
                if (!grep_flags.c_flag && !grep_flags.l_flag) {
                    if (grep_flags.n_flag) {
                        printf("%d:", line_number);
                    }
                    printf("%s\n", str);
                }
                    line_count++;
            }
            free(str);
            str = grep_getline(fp);
            line_number++;
        }
        if (grep_flags.c_flag) {
            printf("%d\n", line_count);
        }
        if (grep_flags.l_flag && line_count > 0) {
            printf("%s\n", filename);
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
