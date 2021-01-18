#include "../includes/ft_printf.h"

void	ft_10(t_form form, va_list *arg, int *cnt)
{
	double  ct[3];
	int	 use[5];
	//f
	/*
	flags : all
	'-' '+' ' ' '#' '0'
	precision
	*/
	ct[0] = va_arg(*arg, double);
	if (form.flag[0])
		form.flag[4] = 0;
	if (ct[0] > 1.7976931348623158e+308 || ct[0] < -1.7976931348623158e+308)
	{
		// if it shows inf, +inf, -inf etc. and ignore flag[4]
		use[0] = 3;
		if (ct[0] < 0.0 || form.flag[1] || form.flag[2])
			use[0]++;
		form.width = (use[0] > form.width ? use[0] : form.width);
		(*cnt) += form.width;
		if (!form.flag[0])
		{
			//activate this if the flag[4] works
			/*if (form.flag[4])
				while (form.width-- > use[0])
					ft_putchar_fd('0', 1);
			else*/
				while (form.width-- > use[0])
					ft_putchar_fd(' ', 1);
		}
		if (ct[0] < 0.0)
			ft_putchar_fd('-', 1);
		else if (form.flag[1])
			ft_putchar_fd('+', 1);
		else if (form.flag[2])
			ft_putchar_fd(' ', 1);
		ft_putstr_fd("inf", 1);
		while ((form.width)-- > use[0])
			ft_putchar_fd(' ', 1);
		return ;
	}
	if (form.precision == -1)
		form.precision = 6;
	ct[1] = ft_round_up(ct, form.precision);
	//round up ct[1] and  here
	use[0] = 1;//count the digits before the decimal point
	if (ct[1] < 0.0)
		ct[1] *= -1.0;
	while (ct[1] >= 10.0)
	{
		ct[1] /= 10.0;
		use[0]++;
	}
	use[1] = use[0]; // the output length without width
	if (form.precision != 0)
		use[1] += form.precision + 1;
	else if (form.flag[3])
		use[1]++;
	if (ct[0] < 0.0 || form.flag[1] || form.flag[2])
		use[1]++;
	form.width -= use[1];
	(*cnt) += use[1];
	if (form.width > 0)
		(*cnt) += form.width;
	if (form.flag[0])
	{
		/*
			sign(+,-,' ') number . precision + ' '
		*/
		if (ct[0] < 0.0)
		{
			ft_putchar_fd('-', 1);
			ct[0] *= -1.0;
		}
		else if (form.flag[1])
			ft_putchar_fd('+', 1);
		else if (form.flag[2])
			ft_putchar_fd(' ', 1);
		ft_putdouble(ct[0], form, use[0]); // care about precision and flag[3]
		while (form.width-- > 0)
			ft_putchar_fd(' ', 1);
	}
	else if (form.flag[4])
	{
		/*
		sign + '0' + number . precision
		*/
		if (ct[0] < 0.0)
		{
			ft_putchar_fd('-', 1);
			ct[0] *= -1.0;
		}
		else if (form.flag[1])
			ft_putchar_fd('+', 1);
		else if (form.flag[2])
			ft_putchar_fd(' ', 1);
		while (form.width-- > 0)
			ft_putchar_fd('0', 1);
		ft_putdouble(ct[0], form, use[0]);
	}
	else
	{
		while (form.width-- > 0)
			ft_putchar_fd(' ', 1);
		if (ct[0] < 0.0)
		{
			ft_putchar_fd('-', 1);
			ct[0] *= -1.0;
		}
		else if (form.flag[1])
			ft_putchar_fd('+', 1);
		else if (form.flag[2])
			ft_putchar_fd(' ', 1);
		ft_putdouble(ct[0], form, use[0]);
	}
}
