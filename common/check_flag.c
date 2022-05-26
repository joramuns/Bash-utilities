//
//  check_flag.c
//  S21 cat and grep
//
//  Created by Joramun Sasin on 5/11/22.
//

#include <string.h>
#include "check_flag.h"
#include "nodes.h"

void init_struct(int mode, flags *a) {
/* Common flags */
    a->flag_mode = mode;
    a->number = 0;
    a->pars_pos = 1;
    a->e_flag = 0;
    a->n_flag = 0;
    a->s_flag = 0;
    a->v_flag = 0;
    switch (mode) {
        case 1:
/* Cat unique flags */
            a->b_flag = 0;
            a->t_flag = 0;
            break;
        case 2:
/* Grep unique flags */
            a->i_flag = 0;
            a->c_flag = 0;
            a->l_flag = 0;
            a->h_flag = 0;
            a->f_flag = 0;
            a->o_flag = 0;
            break;
    }
}

void check_flag(const char *argv[], int argc, flags *a) {
    while (a->flag_mode > 0 && a->pars_pos < argc) {
        char *pointer = (char *)argv[a->pars_pos];
        if (*pointer == '-') {
            a->number++;
            pointer++;
            if (*pointer != '-') {
                short_flag(pointer, a);
            } else {
                pointer++;
                gnu_flag(pointer, a);
            }
            a->pars_pos++;
        } else {
/* Disable flag reading if cat function with flag_mode = 1 */
            if (a->flag_mode == 1) {
                a->flag_mode = 0;
            } else {
                a->pars_pos++;
            }
        }
    }
}

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

int common_sh_flag(char *arg, flags *a) {
    int ex_code = 1;
    switch (*arg) {
        case 'e':
            a->e_flag = 1;
            if (a->flag_mode == 1) {
                a->v_flag = 1;
            } else {
/* Caught -e flag which must stand alone, set flag mode 3 */
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
/* Caught -f flag which must stand alone, set flag mode 3 */
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

/* Validate correctness of -e or -f flag */
int valid_ef(flags *a) {
    int ex_code = 0;
    a->number++;
    return ex_code;
}

void substring(flags *a) {
    a->number++;
}
