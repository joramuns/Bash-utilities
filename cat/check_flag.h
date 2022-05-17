//
//  check_flag.h
//  S21 cat and grep
//
//  Created by Joramun Sasin on 5/11/22.
//

#ifndef check_flag_h
#define check_flag_h

typedef struct flags {
    int flag_true;
    int number;
    int b_flag;
    int e_flag;
    int n_flag;
    int s_flag;
    int t_flag;
    int u_flag;
    int v_flag;
} flags;

int check_flag(char *args, flags *a);

#endif /* check_flag_h */
