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
int fail;
void check()
{

	if (a == b){
		printf("YES : %d\n", a);
	}
	else{
		printf("NO : %d %d \n", a, b);
		fail = 1;
	}
	
}

int main()
{
	fail = 0;
	ft_printf("%.0f %.0f\n", 4.5, -2.5);
	/*#ifdef TEST_0
		if (fail){
			printf("TEST_0 : FAIL\n");
			return (0);
		}

		printf("TEST_0 : SUCCEED\n");
	#endif
	#ifdef TEST_1
		char *s = NULL;
		a = printf("%5.2s\n", s);
		b = ft_printf("%5.2s\n", s);
		check();
		wchar_t *x = malloc(5 * sizeof(wchar_t));
		x[0] = 50;
		x[1] = 0;
		a = printf("%ls\n", x);
		b = ft_printf("%ls\n", x);
		check();
		if (fail){
			printf("TEST_1 : FAIL\n");
			return (0);
		}

		printf("TEST_1 : SUCCEED\n");
	#endif
	#ifdef TEST_2
		a = ft_printf("%.p\n", NULL);
		b = printf("%.p\n", NULL);
		check();
		a = printf("%050p\n\n", &a);
		b = ft_printf("%050p\n\n", &a);
		check();
		a = ft_printf("%p\n\n", NULL);
		b = printf("%p\n\n", NULL);
		check();
		a = ft_printf("%0*.*p\n\n", -20, 12, NULL);
		b = printf("%0*.*p\n\n", -20, 12, NULL);
		check();
		a = ft_printf("%50.2p\n\n", NULL);
		b = printf("%50.2p\n\n", NULL);
		check();
		a = ft_printf("%050.p\n\n", NULL);
		b = printf("%050.p\n\n", NULL);
		check();
		a = ft_printf("%50.p\n\n", NULL);
		b = printf("%50.p\n\n", NULL);
		check();
		a = ft_printf("%-50.p\n\n", NULL);
		b = ft_printf("%-50.p\n\n", NULL);
		check();
		if (fail){
			printf("TEST_2 : FAIL\n");
			return (0);
		}

		printf("TEST_2 : SUCCEED\n");
	#endif
	#ifdef TEST_3
		if (fail){
			printf("TEST_3 : FAIL\n");
			return (0);
		}

		printf("TEST_3 : SUCCEED\n");
	#endif
	#ifdef TEST_4
		if (fail){
			printf("TEST_4 : FAIL\n");
			return (0);
		}

		printf("TEST_4 : SUCCEED\n");
	#endif
	#ifdef TEST_5
		if (fail){
			printf("TEST_5 : FAIL\n");
			return (0);
		}

		printf("TEST_5 : SUCCEED\n");
	#endif
	#ifdef TEST_6
		a = printf("%#.x", 0ULL);
		b = ft_printf("%#.x", 0ULL);
		check();
		if (fail){
			printf("TEST_6 : FAIL\n");
			return (0);
		}

		printf("TEST_6 : SUCCEED\n");
	#endif
	#ifdef TEST_7
		if (fail){
			printf("TEST_7 : FAIL\n");
			return (0);
		}

		printf("TEST_7 : SUCCEED\n");
	#endif
	#ifdef TEST_8
		if (fail){
			printf("TEST_8 : FAIL\n");
			return (0);
		}

		printf("TEST_8 : SUCCEED\n");
	#endif
	#ifdef TEST_9
		if (fail){
			printf("TEST_9 : FAIL\n");
			return (0);
		}

		printf("TEST_9 : SUCCEED\n");
	#endif
	#ifdef TEST_10
		if (fail){
			printf("TEST_10 : FAIL\n");
			return (0);
		}

		printf("TEST_10 : SUCCEED\n");
	#endif
	#ifdef TEST_11
		if (fail){
			printf("TEST_11 : FAIL\n");
			return (0);
		}

		printf("TEST_11 : SUCCEED\n");
	#endif
	#ifdef TEST_12
		if (fail){
			printf("TEST_12 : FAIL\n");
			return (0);
		}

		printf("TEST_12 : SUCCEED\n");
	#endif
	printf("SUCCEED ! \nGood Job !\n");*/
	/*long long n = -9223372036854775807LL;
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
/*
Do I need to deal with error and return -1 ? 
*/
/*
read the subject to make check every bonus
*/

/*
 *Do I need to do (nil) when "%p", NULL ? 
 * */
/*
	TEST(24, print(" %f %f ", LONG_MIN * 1.0, LONG_MAX * 1.0));
	TEST(42, print(" %10f ", 0.0 / 0));
	TEST(43, print(" %10.10f ", 0.0 / 0));
	TEST(44, print(" %0.20f ", 0.0 / 0));
	TEST(45, print(" %020.20f ", 0.0 / 0));
	TEST(46, print(" %-020.20f ", 0.0 / 0));
	TEST(47, print(" %-20.f ", 0.0 / 0));
	TEST(80, print("%.0f", 4.5));
	TEST(81, print("%.0f", -2.5));
	TEST(83, print("%.0f", 2.5));
*/

/*
static double	ft_round_up_sub(int *ct, double *n,
			unsigned long long *stack, double *num)
{
	ct[1] = 1;
	n[1] = 0.0;
	while (--ct[0] >= 0)
	{
		if (ct[1])
		{
			stack[ct[0]]++;
			if (stack[ct[0]] >= 10ULL)
			{
				if (ct[0])
					stack[ct[0]] %= 10ULL;
			}
			else
				ct[1] = 0;
		}
		n[1] /= 10.0;
		n[1] += (double)stack[ct[0]];
	}
	if (ct[2] == -1)
		n[1] *= -1.0;
	return (*num = n[1]);
}

double			ft_round_up(double *num, int precision)
{
	double				n[2];
	unsigned long long	stack[350];
	int					ct[3];

	ct[2] = 1;
	if (*num < 0.0)
		ct[2] *= -1;
	(*num) = (*num) < 0.0 ? (*num) * -1.0 : (*num);
	n[0] = *num;
	stack[0] = (unsigned long long)n[0];
	n[0] -= (double)stack[0];
	ct[0] = 1;
	while (ct[0] <= precision + 1 && ct[0] < 350)
	{
		n[0] *= 10.0;
		stack[ct[0]] = (unsigned long long)n[0];
		n[0] -= (double)stack[ct[0]];
		ct[0]++;
	}
	ct[0]--;
	if (stack[ct[0]] <= 4ULL)
		return (ct[2] == -1 ? *num * -1 : *num);
	return (ft_round_up_sub((int*)ct, (double*)n,
		(unsigned long long*)stack, (double *)num));
}
*/