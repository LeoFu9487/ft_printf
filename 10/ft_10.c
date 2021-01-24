#include "../includes/ft_printf.h"

static void	ft_10_0(t_form form, int *cnt, double ct)
{
	int	use[5];

	use[0] = 3;
	if (ct < 0.0 || form.flag[1] || form.flag[2])
		use[0]++;
	form.width = (use[0] > form.width ? use[0] : form.width);
	(*cnt) += form.width;
	if (!form.flag[0])
		while (form.width-- > use[0])
			ft_putchar_fd(' ', 1);
	if (ct < 0.0)
		ft_putchar_fd('-', 1);
	else if (form.flag[1])
		ft_putchar_fd('+', 1);
	else if (form.flag[2])
		ft_putchar_fd(' ', 1);
	ft_putstr_fd("inf", 1);
	while ((form.width)-- > use[0])
		ft_putchar_fd(' ', 1);
}

static void	ft_10_1_0(t_form form, double *ct, int *use)
{
	if (ct[0] < 0.0)
	{
		ft_putchar_fd('-', 1);
		ct[0] *= -1.0;
	}
	else if (form.flag[1])
		ft_putchar_fd('+', 1);
	else if (form.flag[2])
		ft_putchar_fd(' ', 1);
	if (form.flag[0])
	{
		ft_putdouble(ct[0], form, use[0]);
		while (form.width-- > 0)
			ft_putchar_fd(' ', 1);
	}
	else if (form.flag[4])
	{
		while (form.width-- > 0)
			ft_putchar_fd('0', 1);
		ft_putdouble(ct[0], form, use[0]);
	}
}

static void	ft_10_1(t_form form, int *cnt, double *ct, int *use)
{
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
	if (form.flag[0] || form.flag[4])
		ft_10_1_0(form, ct, use);
	else
	{
		while (form.width-- > 0)
			ft_putchar_fd(' ', 1);
		if (ct[0] < 0.0)
			ft_putchar_fd('-', 1);
		ct[0] = ct[0] < 0.0 ? -1.0 * ct[0] : ct[0];
		if (ct[0] >= 0.0 && form.flag[1])
			ft_putchar_fd('+', 1);
		else if (ct[0] >= 0.0 && form.flag[2])
			ft_putchar_fd(' ', 1);
		ft_putdouble(ct[0], form, use[0]);
	}
}

void		ft_10(t_form form, va_list *arg, int *cnt)
{
	double	ct[3];
	int		use[5];

	ct[0] = va_arg(*arg, double);
	if (form.flag[0])
		form.flag[4] = 0;
	if (ct[0] > 1.7976931348623158e+308 || ct[0] < -1.7976931348623158e+308)
		ft_10_0(form, cnt, ct[0]);
	else
	{
		if (form.precision == -1)
			form.precision = 6;
		ct[1] = ft_round_up(ct, form.precision);
		use[0] = 1;
		ct[1] = ct[1] < 0.0 ? ct[1] * -1.0 : ct[1];
		while (ct[1] >= 10.0)
		{
			ct[1] /= 10.0;
			use[0]++;
		}
		use[1] = use[0];
		ft_10_1(form, cnt, (double*)ct, (int*)use);
	}
}
