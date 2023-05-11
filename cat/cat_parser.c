//
//  check_flag.c
//  S21 cat and grep
//
//  Created by Joramun Sasin on 5/11/22.
//
#include "cat_parser.h"

void check_flag(char *argv[], int argc, flags *a) {
    while (a->flag_mode > 0 && a->pars_pos < argc) {
        char *pointer = (char *)argv[a->pars_pos];
        if (*pointer == '-') {
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
/*      Disable flag reading if found non-flag argument         */
            a->flag_mode = 0;
        }
    }
}

/*                      Reading short flags                     */
void short_flag(char *args, flags *a) {
    while (*args != '\0') {
        switch (*args) {
            case 'e':
                a->e_flag = 1;
                a->v_flag = 1;
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
        args++;
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
        a->flag_mode = -1;
    }
}
