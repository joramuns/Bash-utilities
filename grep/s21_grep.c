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
    if (argc > 2) {
/*                    Read flags                        */
        flags grep_flags = EMPTY_FLAG;
        grep_flags.flag_mode = 2;
        check_flag(argv, argc, &grep_flags);

/*          Read pattern if no -e or -f flag            */
        if (!grep_flags.pattern) {
            add_pattern(argv[grep_flags.pars_pos], &grep_flags);
            argv[grep_flags.pars_pos][0] = '\0';
            grep_flags.pars_pos++;
        }
        num_files(argv, argc, &grep_flags);

/*                 Output each file                     */
        while (grep_flags.pars_pos < argc) {
            if (!*argv[grep_flags.pars_pos]) {
                grep_flags.pars_pos++;
            } else {
                grep_output(grep_flags, argv[grep_flags.pars_pos++]);
            }
        }
        if (grep_flags.pattern) {
            free(grep_flags.pattern);
        }
/* In case of no options called, throw error message    */
    } else {
        fprintf(stderr, "usage: s21_grep [-eivclnhsfo] [pattern] [file ...]");
    }

    return 0;
}

void grep_output(flags grep_flags, const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp) {
        int line_count = in_search(fp, grep_flags, filename);
        af_search(grep_flags, filename, line_count);
        fclose(fp);
    } else if (!grep_flags.s_flag) {
/* Error output excluding -s flag (suppress error message) */
        fprintf(stderr, "grep: %s: %s\n", filename, strerror(errno));
    }
}

int in_search(FILE *fp, flags a, const char *filename) {
    char *str = grep_getline(fp);
    int line_number = 1, line_count = 0;
/*          Used for sensibility of case in pattern     */

    while (str) {
        search(a, filename, &line_count, line_number, str);
        free(str);
        str = grep_getline(fp);
        line_number++;
    }

    return line_count;
}

void search(const flags a, const char *filename, int *line_count, int line_number, char *str) {
    int reg_option = a.i_flag ? REG_ICASE : 0;
    regex_t regex;
    regcomp(&regex, a.pattern,  REG_EXTENDED|reg_option);
    /* Print either matched line (if no -v flag) or other than matched line */
    regmatch_t reg_res[5];
    if (regexec(&regex, str, 5, reg_res, 0) == a.v_flag) {
        /* With -n flag a number of line will be output */
        if (!a.c_flag && !a.l_flag) {
            if (a.num_files && !a.h_flag) {
                printf("%s:", filename);
            }
            if (a.n_flag) {
                printf("%d:", line_number);
            }
            if (a.o_flag && !a.v_flag) {
                char *newstr = str;
                while (!regexec(&regex, newstr, 5, reg_res, 0)) {
                    if (reg_res[0].rm_eo == 0 && reg_res[0].rm_so == 0) {
                        break;
                    }
                    regoff_t len = reg_res[0].rm_eo - reg_res[0].rm_so;
                    newstr += reg_res[0].rm_so;
                    char *substr = strndup(newstr, len);
                    if (substr) {
                        printf("%s\n", substr);
                        free(substr);
                    }
                    newstr += len;
                }
            } else {
                printf("%s\n", str);
            }
        }
        /* Iterate line counter if not -l flag, otherwise - bool */
        a.l_flag ? *line_count = 1 : (*line_count)++;
    }
    regfree(&regex);
}

void af_search(flags a, const char *filename, int line_count) {
    if (a.c_flag) {
        if (a.num_files && !a.h_flag) {
            printf("%s:", filename);
        }
        printf("%d\n", line_count);
    }
    if (a.l_flag && line_count > 0) {
        printf("%s\n", filename);
    }
}
