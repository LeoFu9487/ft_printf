#include "../includes/ft_printf.h"

void ft_2(t_form form, va_list *arg, int *cnt)
{
	// p
	if (form.width > 8)
	{
		(*cnt) += form.width;
		if (form.flag[0])
		{
			ft_itoa_base(va_arg(*arg, void*), "0123456789ABCDEF");
			while (form.width-- > 8)
				ft_putchar_fd(' ', 1);
		}
		else
		{
			while (form.width-- > 8)
				ft_putchar_fd(' ', 1);
			ft_itoa_base(va_arg(*arg, void*), "0123456789ABCDEF");
		}
	}
	else
	{
		(*cnt) += 8;
		ft_itoa_base(va_arg(*arg, void*), "0123456789ABCDEF");
	}
}
