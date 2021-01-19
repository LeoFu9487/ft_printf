#include "../includes/ft_printf.h"
#include <stdio.h>
/*
	

	flags : '-' '+' ' ' '#' '0'
	when there is + and ' ', ignore ' '
	when there is - ignore 0 (only for left pad 0's)
	width: number *
	precision : .number .*
	default 0
	length : l ll h hh
			 0  1 2  3
	convention :
	cspdiuxX%nf g e
	0123456789101112


*/

#include <float.h>
#include <limits.h>
int a,b;
void check()
{
	if (a == b){
		printf("YES : %d\n", a);
	}
	else{
		printf("NO : %d %d \n", a, b);
		printf("press ctrl + c if you want to end the program\n");
		while (1){
			
		}
	}
}

int main()
{
	long long n = -9223372036854775807LL;
	n--;
	a = printf("%lld\n", LLMIN);
	b = ft_printf("%lld\n", LLMIN);
	check();
	
	char *s = 0;
	a = printf("%*.*s\n", -100, 10, s);
	b = ft_printf("%*.*s\n", -100, 10, s);
	check();
	
	a = printf("%*s\n", 12, "123");
	b = ft_printf("%*s\n", 12, "123");
	check();
	
	int x, y;
	a = printf("%*lld%n\n",-100,1234LL, &x);
	b = ft_printf("%*lld%n\n",-100,1234LL, &y);
	check();
	
	a = printf("%lld%lln\n", 0LL, &n);
	b = ft_printf("%lld%lln\n", 0LL, &n);
	check();


	//b = ft_printf("%50%%50.30%%.15%%015%%*.*%\n",-20,15);
	//check();
	//a = printf("%s\n, ");
	/*double a = 1e300 * -1e20;//= DBL_MAX - 10.0;
	int n;
	printf("%.300f\n", a);
	ft_printf("%-100.300f%n\n",a, &n);
	printf("%d\n", n);
	*/
	//unsigned long long a= ULLONG_MAX;
	//int b,c;
	/*double a = -9.448487;
	
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
	*/
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
