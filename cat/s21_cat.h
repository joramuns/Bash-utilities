//
//  s21_cat.h
//  S21 cat and grep
//
//  Created by Joramun Sasin on 5/11/22.
//

#ifndef s21_cat_h
#define s21_cat_h
#include"check_flag.h"

void output(flags cat_flags, const char *filename);
void new_line(flags cat_flags, int *counter, int *line);

#endif /* s21_cat_h */
