#include "../includes/ft_printf.h"

void ft_0_0(t_form form, va_list *arg, int *cnt)
{
	/*
	c
	length 0 not finished yet
	*/
	if (form.width > 1 && form.flag[0] == 0)
	{
		(*cnt) += form.width;
		if (form.flag[4])
			while ((form.width)-- > 1)
				ft_putchar_fd('0', 1);
		else
			while ((form.width)-- > 1)
				ft_putchar_fd(' ', 1);
		ft_putchar_fd(va_arg(*arg, wint_t), 1);
	}
	else
	{
		ft_putchar_fd(va_arg(*arg, wint_t), 1);
		if (form.width > 1)
		{
			(*cnt) += form.width;
			while ((form.width)-- > 1)
			ft_putchar_fd(' ', 1);
		}
		else
			(*cnt)++;
	}
}