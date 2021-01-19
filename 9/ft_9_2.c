#include "../includes/ft_printf.h"

void ft_9_2(va_list *arg, int *cnt)
{
	short int	*va;

	va = va_arg(*arg, short int*);
	*va = *(short int*)cnt;
}
