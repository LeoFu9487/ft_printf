#include "../includes/ft_printf.h"

void ft_9_3(t_form form, va_list *arg, int *cnt)
{
	signed char	*va;

	va = va_arg(*arg, signed char*);
	*va = *(signed char*)cnt;
}
