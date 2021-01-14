#include "../includes/ft_printf.h"

void ft_9_1(t_form form, va_list *arg, int *cnt)
{
	long long int	*va;

	va = va_arg(*arg, long long int*);
	*va = *(long long int*)cnt;
}
