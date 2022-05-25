//
//  check_flag.h
//  S21 cat and grep
//
//  Created by Joramun Sasin on 5/11/22.
//
#ifndef SRC_CAT_CHECK_FLAG_H_
#define SRC_CAT_CHECK_FLAG_H_

typedef struct flags {
/* Flags 0 and 1 for strict parsing in cat, flag 2 - for grep */
    int flag_mode;
    int number;
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
} flags;

void init_struct(int mode);
void check_flag(char *argv[], int argc, flags *a);
void short_flag(char *args, flags *a);
int common_sh_flag(char arg, flags *a);
void cat_sh_flag(char arg, flags *a);
void grep_sh_flag(char arg, flags *a);
void gnu_flag(char *args, flags *a);

#endif  // SRC_CAT_CHECK_FLAG_H_
