//
//  check_flag.h
//  S21 cat and grep
//
//  Created by Joramun Sasin on 5/11/22.
//
#ifndef SRC_CAT_CAT_PARSER_H_
#define SRC_CAT_CAT_PARSER_H_
#define EMPTY_FLAG {1, 1, 0, 0, 0, 0, 0, 0}
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

typedef struct flags {
/*              Flag modes:                 */
/* 0 and 1 for strict parsing in cat        */
    int flag_mode;
    int pars_pos;
    int b_flag;
    int e_flag;
    int n_flag;
    int s_flag;
    int t_flag;
    int v_flag;
} flags;

void    check_flag(char *argv[], int argc, flags *a);
void    short_flag(char *args, flags *a);
void    gnu_flag(char *args, flags *a);


#endif  // SRC_CAT_CAT_PARSER_H_
