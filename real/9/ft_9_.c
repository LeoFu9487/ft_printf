#include "../includes/ft_printf.h"

void ft_9_(t_form form, va_list *arg, int *cnt)
{
	int *va;

	va = va_arg(*arg, int*);
	*va = *cnt;
}
