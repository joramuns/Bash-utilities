//
//  s21_grep.h
//  S21 cat and grep
//
//  Created by Joramun Sasin on 5/20/22.
//

#ifndef SRC_GREP_S21_GREP_H_
#define SRC_GREP_S21_GREP_H_
#include "grep_parser.h"
#include <stdio.h>
#include <regex.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void    grep_output(flags grep_flags, const char *filename);
int     in_search(FILE *fp, flags a, const char *filename);
void    search(const flags a, const char *filename, int *line_count, int line_number, char *str);
void    af_search(flags a, const char *filename, int line_count);
void    buggy_original_grep_output(char *patterns, char *str, int reg_option);

#endif  // SRC_GREP_S21_GREP_H_
