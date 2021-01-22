#include "../includes/ft_printf.h"

void	ft_3(t_form form, va_list *arg, int *cnt)
{
	if (form.length == 0)
		ft_3_0(form, arg, cnt);
	else if (form.length == 1)
		ft_3_1(form, arg, cnt);
	else if (form.length == 2)
		ft_3_2(form, arg, cnt);
	else if (form.length == 3)
		ft_3_3(form, arg, cnt);
	else
		ft_3_(form, arg, cnt);
}
