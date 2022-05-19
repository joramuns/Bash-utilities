//
//  check_flag.c
//  S21 cat and grep
//
//  Created by Joramun Sasin on 5/11/22.
//

#include "check_flag.h"
#include <string.h>

int check_flag(char *argv[], int argc, flags *a) {
    int i = 1;
    while (a->flag_true == 1 && i < argc) {
        if (*argv[i] == '-') {
            a->number++;
            argv[i]++;
            if (*argv[i] != '-') {
                short_flag(argv[i], a);
            } else {
                argv[i]++;
                gnu_flag(argv[i], a);
            }
        } else {
            a->flag_true = 0;
        }
        i++;
    }

    return i;
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
