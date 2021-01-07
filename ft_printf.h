#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

typedef struct  s_form
{
    /*
    [flags][width][.precision][length]specifier


    flags : '-' '+' ' ' '#' '0'
    when there is + and ' ', ignore ' '
    when there is - ignore 0 (only for left pad 0's)
    width: number *
    precision : .number .*
    default 0
    length : l ll h hh
             1  2 3  4
    */

    int flag[5];
    int width;
    int precision;
    int length;
    /*
    cspdiuxX%nf g e
    0123456789101112
    */
    int convention;
}               t_form;

int     ft_printf(const char *input, ...);
void    ft_get_form(char **str, va_list *arg, t_form *form);
void    ft_out(t_form form, va_list *arg, int *cnt);
void    ft_itoa_base(void* num, const char *base);

#endif
