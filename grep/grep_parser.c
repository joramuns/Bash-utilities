//
//  check_flag.c
//  S21 cat and grep
//
//  Created by Joramun Sasin on 5/11/22.
//
#include "grep_parser.h"

void check_flag(char *argv[], int argc, flags *a) {
    while (a->flag_mode > 0 && a->pars_pos < argc) {
        char *pointer = (char *)argv[a->pars_pos];
/*  Parser has found -e of -f flag and goes reading a string    */
        if (a->e_flag) {
            add_pattern(pointer, a);
            pointer[0] = '\0';
            a->e_flag = 0;
        }
        if (a->f_flag) {
            get_patterns(a, pointer);
            pointer[0] = '\0';
            a->f_flag = 0;
        }
        if (*pointer == '-') {
            pointer++;
            short_flag(pointer, a);
            argv[a->pars_pos][0] = '\0';
            a->pars_pos++;
        } else {
            a->pars_pos++;
        }
    }
/*          Set parser position to first actual argument        */
    for (a->pars_pos = 1; a->pars_pos < argc; a->pars_pos++) {
        if (*argv[a->pars_pos]) {
            break;
        }
    }
}

/*                  Read every letter in grep flags             */
void short_flag(char *args, flags *a) {
    while (*args != '\0') {
        grep_sh_flag(*args, a);
        args++;
    }
}

/*                          Recognize grep flag                 */
void grep_sh_flag(char arg, flags *a) {
    switch (arg) {
        case 'e':
            a->e_flag = 1;
            break;
        case 'n':
            a->n_flag = 1;
            break;
        case 's':
            a->s_flag = 1;
            break;
        case 'v':
            a->v_flag = 1;
            break;
        case 'i':
            a->i_flag = 1;
            break;
        case 'c':
            a->c_flag = 1;
            break;
        case 'l':
            a->l_flag = 1;
            break;
        case 'h':
            a->h_flag = 1;
            break;
        case 'f':
            a->f_flag = 1;
            break;
        case 'o':
            if (a->o_flag != -1) {
                a->o_flag = 1;
            }
            break;
        default:
            a->flag_mode = -1;
            break;
    }
}

/*               Validate correctness of -e or -f flag          */
//    int valid_ef(flags *a) {
//        int ex_code = 0;
//        return ex_code;
//    }
//
//    void substring(flags *a) {
//        int ex_code = 0;
//        return ex_code;
//    }

/*           Counting the amount of given files to read         */
void num_files(char *argv[], int argc, flags *a) {
    int pos = a->pars_pos;

    while (pos < argc) {
        if (*argv[pos]) {
            a->num_files++;
        }
        pos++;
    }
    if (a->num_files > 0) {
        a->num_files--;
    }
}

void add_pattern(char *arg, flags *a) {
    size_t arg_len = 0;
    if (arg) {
        arg_len = strlen(arg);
    }
/*                  Malloc pattern and destroy argument         */
    if (!a->pattern) {
        a->pattern = (char *)malloc(sizeof(char) * (arg_len + 1));
        if (a->pattern) {
            strcpy(a->pattern, arg);
        }
/* If pattern is already existed, realloc it and do the same    */
    } else {
        /* Sum two lengths, plus one null plus one separator for regex  */
        size_t len = strlen(a->pattern) + arg_len + 2;
        char *temp_line = realloc(a->pattern, sizeof(char) * (len));
/*                         Realloc safely please!                       */
        if (temp_line) {
            a->pattern = temp_line;
            strcat(a->pattern, "|");
            strcat(a->pattern, arg);
        } else {
            free(a->pattern);
            a->pattern = NULL;
        }
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

void get_patterns(flags *a, char *pattern_filename) {
    FILE *fpp = fopen(pattern_filename, "r");
    if (fpp) {
        char *fpattern = NULL;
        while ((fpattern = grep_getline(fpp)) != NULL) {
            if (*fpattern != '\0') {
                add_pattern(fpattern, a);
            } else {
                a->o_flag = -1;
                add_pattern(".*", a);
            }
            free(fpattern);
        }
        fclose(fpp);
    } else {
        /* Error output */
        fprintf(stderr, "grep: %s: %s\n", pattern_filename, strerror(errno));
    }
}
