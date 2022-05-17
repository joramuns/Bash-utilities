//
//  check_flag.c
//  S21 cat and grep
//
//  Created by Joramun Sasin on 5/11/22.
//

#include "check_flag.h"

int check_flag(char *args, flags *a) {
    if (*args == '-') {
        args++;
        while (*args != '\0') {
            switch (*args) {
                case 'b':
                    if (!a->n_flag) {
                        a->b_flag++;
                    }
                    a->number++;
                    break;
                case 'e':
                    a->e_flag++;
                    a->number++;
                    break;
                case 'n':
                    a->n_flag++;
                    a->b_flag = 0;
                    a->number++;
                    break;
                case 's':
                    a->s_flag++;
                    a->number++;
                    break;
                case 't':
                    a->t_flag++;
                    a->number++;
                    break;
                case 'u':
                    a->u_flag++;
                    a->number++;
                    break;
                case 'v':
                    a->v_flag++;
                    a->number++;
                    break;
                default:
                    a->number = -1;
                    a->flag_true = 0;
                    break;
            }
            args++;
        }
    } else {
        a->flag_true = 0;
    }

    return a->number;
}
