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
    unsigned long long a= ULLONG_MAX,b = 0;
    char s[] = "%#110llx!%-100.4llx!\n";
    if (printf(s, a, b)
    == ft_printf(s, a, b))
        printf("YES\n");
    else
    {
        printf("NO\n");
    }
}

/*
 git add ft_itoa_base.c ft_printf.c ft_printf.h parse.c out.c ft_put.c main.c
 git commit -m "autocommit"
 git push
*/
/*
try long long min
*/
