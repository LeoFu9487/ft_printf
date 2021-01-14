#include "../includes/ft_printf.h"

void ft_9(t_form form, va_list *arg, int *cnt)
{
	//n
	if (form.length == 0)
		ft_9_0(form, arg, cnt);
	else if (form.length == 1)
		ft_9_1(form, arg, cnt);
	else if (form.length == 2)
		ft_9_2(form, arg, cnt);
	else if (form.length == 3)
		ft_9_3(form, arg, cnt);
	else
		ft_9_(form, arg, cnt);
}
