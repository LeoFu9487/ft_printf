#include "../includes/ft_printf.h"

/*
not finished yet
*/
void	ft_12(t_form form, va_list *arg, int *cnt)
{
	//e
	/*
	1.7E +/- 308 (15 digits)
	flag : all
	precision : yes
	*/
	/*
	[number]e[sign][two digits or three digits]
	*/
	double	n[5];
	int		ct[5];

	ct[4] = 1;
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
	ct[0] = 0;
	if (n[0] < 0.0)
	{
		n[0] *= -1.0;
		ct[4] = -1;
	}
	while (n[0] >= 10.0)
	{
		n[0] /= 10.0;
		ct[0]++;
	}
	while (n[0] < 1.0)
	{
		n[0] *= 10.0;
		ct[0]--;
	}
	ft_round_up(n, form.precision);
	if (n[0] >= 10.0)
	{
		n[0] /= 10.0;
		ct[0]++;
	}
	//ct[1] for counting the length of output
	ct[1] = 5; // the number before decimal point and the scientific notation : e+99
	if (form.precision || form.flag[3])
		ct[1] += 1 + form.precision;
	if (ct[0] > 99 || ct[0] < -99)
		ct[1] += 1;
	if (ct[4] == -1 || form.flag[1] || form.flag[2])
		ct[1]++;
	form.width = (ct[1] > form.width ? ct[1] : form.width);
	(*cnt) += form.width;
	//' '-> sign->'0'
	if ((!form.flag[0]) && (!form.flag[4]))
		while (form.width-- > ct[1])
			ft_putchar_fd(' ', 1);
	if (ct[4] == -1)
		ft_putchar_fd('-', 1);
	else if (form.flag[1])
		ft_putchar_fd('+', 1);
	else if (form.flag[2])
		ft_putchar_fd(' ', 1);
	if (!(form.flag[0]) && form.flag[4])
		while (form.width-- > ct[1])
			ft_putchar_fd('0', 1);
	/*
	put the number, consider the flag[3] and precision
	*/
	ft_put_flag_e(n[0], ct[0], form);
	if (form.flag[0])
		while (form.width-- > ct[1])
			ft_putchar_fd(' ', 1);
}
