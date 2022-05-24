//
//  check_flag.c
//  S21 cat and grep
//
//  Created by Joramun Sasin on 5/11/22.
//

#include "check_flag.h"
#include <string.h>

int check_flag(char *argv[], int argc, flags *a) {
    while (a->flag_true == 1 && a->pars_pos < argc) {
        if (*argv[a->pars_pos] == '-') {
            a->number++;
            argv[a->pars_pos]++;
            if (*argv[a->pars_pos] != '-') {
                short_flag(argv[a->pars_pos], a);
            } else {
                argv[a->pars_pos]++;
                gnu_flag(argv[a->pars_pos], a);
            }
            a->pars_pos++;
        } else {
            a->flag_true = 0;
        }
    }

    return 0;
}

void short_flag(char *args, flags *a) {
    while (*args != '\0') {
        switch (*args) {
            case 'b':
                a->b_flag = 1;
                break;
            case 'e':
                a->e_flag = 1;
                a->v_flag = 1;
                break;
            case 'E':
                a->e_flag = 1;
                break;
            case 'n':
                a->n_flag = 1;
                break;
            case 's':
                a->s_flag = 1;
                break;
            case 't':
                a->t_flag = 1;
                a->v_flag = 1;
                break;
            case 'T':
                a->t_flag = 1;
                break;
            case 'u':
                a->u_flag = 1;
                break;
            case 'v':
                a->v_flag = 1;
                break;
            case 'i':
                a->i_flag = 1;
                break;
            default:
                a->number = -1;
                a->flag_true = 0;
                break;
        }
        args++;
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
        a->flag_true = 0;
    }
}
