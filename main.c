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
    //printf("%.f\n",0.4999999);
    //unsigned long long a= ULLONG_MAX;
    //int b,c;
    double a = 99.0;
    char s[] = "%#+100.2fx\n";
    if (printf(s, a)
    == ft_printf(s, a))
        printf("YES\n");
    else
    {
        printf("NO\n");
    }
    /*
    try integer input with zero precision
    */
}

/*
 git add ft_itoa_base.c ft_printf.c ft_printf.h parse.c out.c ft_put.c main.c ft_putdouble.c
 git commit -m "%f"
 git push

*/
/*
try long long min
*/
/*
check all the malloc and remember to free everything
make sure every function is allowed
*/
