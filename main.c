#include "ft_printf.h"
#include <stdio.h>

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
    convention :
    cspdiuxX%nf g e
    0123456789101112
*/

#include <limits.h>
int main()
{
    //int a = 55;
    if (printf("%50.30lld\n", LONG_LONG_MIN)
    == ft_printf("%50.30lld\n", LONG_LONG_MIN))
        printf("YES\n");
    else
        printf("NO\n");
}
/*
 git add ft_itoa.c ft_printf.c ft_printf.h parse.c out.c ft_put.c
*/
/*
try long long min
*/
