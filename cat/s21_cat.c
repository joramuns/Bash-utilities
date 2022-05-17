//
//  s21_cat.c
//  S21 cat and grep
//
//  Created by Joramun Sasin on 5/11/22.
//
#include <stdarg.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "s21_cat.h"
#include "check_flag.h"


int main(int argc, char *argv[]) {

    /* OUTPUT PART of commandline arguments */
    int argc_temp = 1;
    while (argc_temp < argc) {
        printf("argv %d = %s\n", argc_temp, argv[argc_temp]);
        argc_temp++;
    }
    /* END OF OUTPUT PART */
    
    int i = 1;
    flags cat_flags = {1, 0, 0, 0, 0, 0, 0, 0, 0};
    while (cat_flags.flag_true == 1 && i < argc) {
        check_flag(argv[i++], &cat_flags);
    }
    i--;
    printf("number of flags: %d\n", cat_flags.number);

    FILE *fp = fopen("test2.txt", "r");
    
    int c = 0;
    if (fp) {
//        while (!feof(fp)) {
        printf("hello %p\n", fp);
            c = fgetc(fp);
        printf("c = %c\n", c);
            putchar(c);
//        }
    } else {
        printf("Error no = %s\n", strerror(errno));
    }
    fclose(fp);

    return 0;
}
