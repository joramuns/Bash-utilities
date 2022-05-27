//
//  check_flag.c
//  S21 cat and grep
//
//  Created by Joramun Sasin on 5/11/22.
//

#include <string.h>
#include "check_flag.h"
#include <stdlib.h>

void check_flag(char *argv[], int argc, flags *a) {
    while (a->flag_mode > 0 && a->pars_pos < argc) {
        char *pointer = (char *)argv[a->pars_pos];
/*  Parser has found -e of -f flag and goes reading a string    */
        if (a->flag_mode == 3) {
            // go to read argument
            add_pattern(argv, a);
//            a->pars_pos++;
            a->flag_mode = 2;
            // next pars position
        }
        if (a->flag_mode == 4) {
            // go to read filename
            // next pars position
        }
        if (*pointer == '-') {
            a->number++;
            pointer++;
            if (*pointer != '-') {
                short_flag(pointer, a);
            } else {
                pointer++;
                gnu_flag(pointer, a);
            }
            argv[a->pars_pos][0] = '\0';
            a->pars_pos++;
        } else {
/* Disable flag reading if cat function with flag_mode = 1      */
/* In case of grep function - go to the next argument           */
            if (a->flag_mode == 1) {
                a->flag_mode = 0;
            } else {
                a->pars_pos++;
            }
        }
    }
}

/* First, read common cat and grep flags, then go to different  */
void short_flag(char *args, flags *a) {
    while (*args != '\0') {
        if (!common_sh_flag(args, a)) {
            if (a->flag_mode == 1) {
                cat_sh_flag(*args, a);
            } else if (a->flag_mode == 2) {
                grep_sh_flag(*args, a);
            }
        }
        if (a->flag_mode == 3) {
        }
        args++;
        if (valid_ef(a)) {
            substring(a);
        }
    }
}

/*              Reading common cat and grep flags               */
int common_sh_flag(char *arg, flags *a) {
    int ex_code = 1;
    switch (*arg) {
        case 'e':
            a->e_flag = 1;
            if (a->flag_mode == 1) {
                a->v_flag = 1;
            } else {
/* Caught -e flag which must stand alone, set flag mode 3       */
                a->flag_mode = 3;
            }
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
        default:
            ex_code = 0;
            break;
    }

    return ex_code;
}

/*                Reading cat unique flags                      */
void cat_sh_flag(char arg, flags *a) {
    switch (arg) {
        case 'b':
            a->b_flag = 1;
            break;
        case 'E':
            a->e_flag = 1;
            break;
        case 't':
            a->t_flag = 1;
            a->v_flag = 1;
            break;
        case 'T':
            a->t_flag = 1;
            break;
        default:
            a->flag_mode = -1;
            break;
    }
}

/*                  Reading grep unique flags                   */
void grep_sh_flag(char arg, flags *a) {
    switch (arg) {
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
/*      Caught -f flag which must stand alone, set flag mode 3  */
            a->flag_mode = 3;
            break;
        case 'o':
            a->o_flag = 1;
            break;
        default:
            a->flag_mode = -1;
            break;
    }
}

/*                      Reading long GNU flags                  */
void gnu_flag(char *args, flags *a) {
    if (!strcmp(args, "number-nonblank")) {
        a->b_flag = 1;
    } else if (!strcmp(args, "number")) {
        a->n_flag = 1;
    } else if (!strcmp(args, "squeeze-blank")) {
        a->s_flag = 1;
    } else {
        a->number = -1;
        a->flag_mode = 0;
    }
}

/*               Validate correctness of -e or -f flag          */
int valid_ef(flags *a) {
    int ex_code = 0;
    a->number++;
    return ex_code;
}

void substring(flags *a) {
    a->number++;
}

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

void add_pattern(char **argv, flags *a) {
/*                  Malloc pattern and destroy argument         */
    if (!a->pattern) {
        a->pattern = (char *)malloc(sizeof(char) * (strlen(argv[a->pars_pos]) +1));
        if (a->pattern) {
            strcpy(a->pattern, argv[a->pars_pos]);
            argv[a->pars_pos][0] = '\0';
        }
/* If pattern is already existed, realloc it and do the same    */
    } else {
        size_t pat_len = strlen(a->pattern);
        size_t len = strlen(a->pattern) + 1;
/* Sum two lengths, plus one null plus one separator for regex  */
        len += pat_len + 1;
        char *temp_line = realloc(a->pattern, sizeof(char) * (len));
/*                     Realloc safely please!                   */
        if (temp_line) {
            a->pattern = temp_line;
            strcat(a->pattern, "|");
            strcat(a->pattern, argv[a->pars_pos]);
            argv[a->pars_pos][0] = '\0';
        } else {
            free(a->pattern);
            a->pattern = NULL;
        }
    }
}
