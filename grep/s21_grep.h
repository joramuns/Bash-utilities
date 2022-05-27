//
//  s21_grep.h
//  S21 cat and grep
//
//  Created by Joramun Sasin on 5/20/22.
//

#ifndef SRC_GREP_S21_GREP_H_
#define SRC_GREP_S21_GREP_H_
#include "../common/check_flag.h"
#include <stdio.h>
#include <regex.h>

void    grep_output(flags grep_flags, const char *filename);
char    *grep_getline(FILE *filepointer);
int     in_search(FILE *fp, regex_t *regex, flags a, const char *filename);
void    af_search(flags a, const char *filename, int line_count);

#endif  // SRC_GREP_S21_GREP_H_
