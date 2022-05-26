//
//  check_flag.h
//  S21 cat and grep
//
//  Created by Joramun Sasin on 5/11/22.
//
#ifndef SRC_COMMON_CHECK_FLAG_H_
#define SRC_COMMON_CHECK_FLAG_H_
#define EMPTY_FLAG {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

typedef struct flags {
/*              Flag modes:                 */
/* 0 and 1 for strict parsing in cat        */
/* 2 - normal grep mode parsing             */
/* 3 - caught -e or -f flag, seek substring */
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

void    init_struct(int mode, flags *a);
void    check_flag(const char *argv[], int argc, flags *a);
void    short_flag(char *args, flags *a);
int     common_sh_flag(char *arg, flags *a);
void    cat_sh_flag(char arg, flags *a);
void    grep_sh_flag(char arg, flags *a);
void    gnu_flag(char *args, flags *a);
int    valid_ef(flags *a);
void    substring(flags *a);

#endif  // SRC_COMMON_CHECK_FLAG_H_
