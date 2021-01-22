#include "../includes/ft_printf.h"

void	ft_9_3(va_list *arg, int *cnt)
{
	signed char	*va;

	va = va_arg(*arg, signed char*);
	*va = (signed char)(*cnt);
}
