#include "../includes/ft_printf.h"

void	ft_6(t_form form, va_list *arg, int *cnt)
{
	if (form.length == 0)
		ft_6_0(form, arg, cnt);
	else if (form.length == 1)
		ft_6_1(form, arg, cnt);
	else if (form.length == 2)
		ft_6_2(form, arg, cnt);
	else if (form.length == 3)
		ft_6_3(form, arg, cnt);
	else
		ft_6_(form, arg, cnt);
}
