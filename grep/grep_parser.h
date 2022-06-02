//
//  check_flag.h
//  S21 cat and grep
//
//  Created by Joramun Sasin on 5/11/22.
//
#ifndef SRC_GREP_GREP_PARSER_H_
#define SRC_GREP_GREP_PARSER_H_
#define EMPTY_FLAG {2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, NULL}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

typedef struct flags {
/*              Flag modes:                 */
/* 2 - normal grep mode parsing             */
/* 3 - caught -e flag, seek substring       */
/* 4 - caught -f flag, seek substring       */
    int flag_mode;
    int pars_pos;
    int b_flag;
    int e_flag;
    int n_flag;
    int s_flag;
    int t_flag;
    int u_flag;
    int v_flag;
    int i_flag;
    int c_flag;
    int l_flag;
    int h_flag;
    int f_flag;
    int o_flag;
    int num_files;
    char *pattern;
} flags;

void    check_flag(char *argv[], int argc, flags *a);
void    short_flag(char *args, flags *a);
void    grep_sh_flag(char arg, flags *a);
//    int     valid_ef(flags *a);
//    void    substring(flags *a);
void    num_files(char *argv[], int argc, flags *a);
void    add_pattern(char *arg, flags *grep_flags);
char    *grep_getline(FILE *filepointer);
void    get_patterns(flags *a, char *pattern_filename);

#endif  // SRC_GREP_GREP_PARSER_H_
