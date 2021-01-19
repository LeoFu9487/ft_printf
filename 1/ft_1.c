#include "../includes/ft_printf.h"

void ft_1(t_form form, va_list *arg, int *cnt)
{
	char	*out;

	if (form.length == 0)
	{
		ft_1_0(form, arg, cnt);
		return ;
	}
	out = va_arg(*arg, char*);
	if (out == NULL)
		out = "(null)";
	if (form.precision == -1)
		form.precision = (int)ft_strlen(out);
	else if (form.precision > (int)ft_strlen(out))
		form.precision = (int)ft_strlen(out);
	if (form.width > form.precision)
	{
		(*cnt) += form.width;
		if (form.flag[0] == 0)
		{
			if (form.flag[4])
				while (form.width-- > form.precision)
					ft_putchar_fd('0', 1);
			else
				while (form.width-- > form.precision)
					ft_putchar_fd(' ', 1);
		}
		while (form.precision-- > 0)
			ft_putchar_fd(*(out++), 1);
		if (form.flag[0])
			while (form.width-- > form.precision)
				ft_putchar_fd(' ', 1);
		return ;
	}
	(*cnt) += form.precision;
	while (form.precision-- > 0)
			ft_putchar_fd(*(out++), 1);
}
