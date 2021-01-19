#include "../includes/ft_printf.h"

void ft_9_(va_list *arg, int *cnt)
{
	int *va;

	va = va_arg(*arg, int*);
	*va = *cnt;
}