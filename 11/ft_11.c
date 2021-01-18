#include "../includes/ft_printf.h"

void	ft_11(t_form form, va_list *arg, int *cnt)
{
	//g
	double	n[5];
	int		ct[5];

	n[0] = va_arg(*arg, double);
	if (form.precision == -1)
		form.precision = 6;
	if (n[0] > 1.7976931348623158e+308 || n[0] < -1.7976931348623158e+308)
	{
		// if it shows inf, +inf, -inf etc. and ignore flag[4]
		ct[0] = 3;
		if (n[0] < 0.0 || form.flag[1] || form.flag[2])
			ct[0]++;
		form.width = (ct[0] > form.width ? ct[0] : form.width);
		(*cnt) += form.width;
		if (!form.flag[0])
		{
			// activate this if flag[4] works
			/*if (form.flag[4])
				while (form.width-- > ct[0])
					ft_putchar_fd('0', 1);
			else*/
				while (form.width-- > ct[0])
					ft_putchar_fd(' ', 1);
		}
		if (n[0] < 0.0)
			ft_putchar_fd('-', 1);
		else if (form.flag[1])
			ft_putchar_fd('+', 1);
		else if (form.flag[2])
			ft_putchar_fd(' ', 1);
		ft_putstr_fd("inf", 1);
		while ((form.width)-- > ct[0])
			ft_putchar_fd(' ', 1);
		return ;
	}
	ft_put_flag_g(n[0], form, cnt);
}
