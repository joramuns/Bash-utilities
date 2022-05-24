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

void grep_output(flags grep_flags, const char *filename, const char *pattern);
char *grep_getline(FILE *filepointer);

#endif  // SRC_GREP_S21_GREP_H_
