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


#include <float.h>
#include <limits.h>
int main()
{
	/*double a = 1e300 * -1e20;//= DBL_MAX - 10.0;
	int n;
	printf("%.300f\n", a);
	ft_printf("%-100.300f%n\n",a, &n);
	printf("%d\n", n);
	*/
	//unsigned long long a= ULLONG_MAX;
	//int b,c;
	double a = -9.448487;
	
	int b,c;
	char s[] = "%e\n";
	b = printf(s, a);
	c = ft_printf(s, a);
	if ( b == c)
		printf("YES %d\n", b);
	else
	{
		printf("NO %d %d\n",b,c);
	}
	
	/*
	try integer input with zero precision
	try %.0%
	*/
	
	return 0;
}

/*
 git add ft_itoa_base.c ft_printf.c ft_printf.h parse.c out.c ft_put.c main.c ft_putdouble.c ft_put_flag_e.c ft_put_flag_g.c
 git commit -m "%g"
 git push

*/
/*
how to fix double max
*/
/*
Do I need to print inf for %f%e%g ? 
do the flags work ? flag[4]
*/
/*
when I put too many digits of double, I need to put 0 instead ? 
*/
/*
check all the malloc and remember to free everything
make sure every function is allowed
*/
