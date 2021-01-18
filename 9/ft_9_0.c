#include "../includes/ft_printf.h"

void ft_9_0(t_form form, va_list *arg, int *cnt)
{
	long int	*va;

	va = va_arg(*arg, long int*);
	*va = *(long int*)cnt;
}
