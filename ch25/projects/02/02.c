#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>


int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "usage: %s localename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (setlocale(LC_ALL, argv[1]) == NULL) {
        fprintf(stderr, "bad locale string\n");
        exit(EXIT_FAILURE);
    }

    struct lconv *locale = localeconv();

    printf("decimal_point = \"%s\"\n", locale->decimal_point);
    printf("thousands_sep = \"%s\"\n", locale->thousands_sep);

    printf("grouping = ");
    for (size_t i = 0; i < strlen(locale->grouping); ++i) {
        printf("%hhd ", locale->grouping[i]);
    }
    putchar('\n');

    printf("mon_decimal_point = \"%s\"\n", locale->mon_decimal_point);
    printf("mon_thousands_sep = \"%s\"\n", locale->mon_thousands_sep);

    printf("mon_grouping = ");
    for (size_t i = 0; i < strlen(locale->mon_grouping); ++i) {
        printf("%hhd ", locale->mon_grouping[i]);
    }
    putchar('\n');

    printf("positive_sign = \"%s\"\n", locale->positive_sign);
    printf("negative_sign = \"%s\"\n", locale->negative_sign);
    printf("currency_symbol = \"%s\"\n", locale->currency_symbol);
    printf("frac_digits = %hhd\n", locale->frac_digits);
    printf("p_cs_precedes = %hhd\n", locale->p_cs_precedes);
    printf("n_cs_precedes = %hhd\n", locale->n_cs_precedes);
    printf("p_sep_by_space = %hhd\n", locale->p_sep_by_space);
    printf("n_sep_by_space = %hhd\n", locale->n_sep_by_space);
    printf("p_sign_posn = %hhd\n", locale->p_sign_posn);
    printf("n_sign_posn = %hhd\n", locale->n_sign_posn);
    printf("int_curr_symbol = \"%s\"\n", locale->int_curr_symbol);
    printf("int_frac_digits = %hhd\n", locale->int_frac_digits);

    // not supported by msvc compiler
    // printf("int_p_cs_precedes = %c\n", locale->int_p_cs_precedes);
    // printf("int_n_cs_precedes = %c\n", locale->int_n_cs_precedes);
    // printf("int_p_sep_by_space = %c\n", locale->int_p_sep_by_space);
    // printf("int_n_sep_by_space = %c\n", locale->int_n_sep_by_space);
    // printf("int_p_sign_posn = %c\n", locale->int_p_sign_posn);
    // printf("int_n_sign_posn = %c\n", locale->int_n_sign_posn);
}