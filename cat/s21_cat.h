//
//  s21_cat.h
//  S21 cat and grep
//
//  Created by Joramun Sasin on 5/11/22.
//
#ifndef SRC_CAT_S21_CAT_H_
#define SRC_CAT_S21_CAT_H_
#include "cat_parser.h"

void cat_output(flags cat_flags, const char *filename);
void new_line(flags *cat_flags, int *counter, int *line, int c);
void cat_np_output(flags flags, int *c);
void priorities(flags *flags);

#endif  // SRC_CAT_S21_CAT_H_
