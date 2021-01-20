#include "../includes/ft_printf.h"

static void	ft_3_2_0(t_form form, int *cnt)
{
	if (form.flag[1] || form.flag[2])
	{
		(*cnt)++;
		form.width--;
	}
	(*cnt) += ft_max(0, form.width);
	if (form.flag[0] == 0)
		while (form.width-- > 0)
			ft_putchar_fd(' ', 1);
	if (form.flag[1] || form.flag[2])
		ft_putchar_fd(form.flag[1] ? '+' : ' ', 1);
	while (form.width-- > 0)
		ft_putchar_fd(' ', 1);
}

static void	ft_3_2_1_0(t_form form, int *cnt)
{
	(*cnt) += ft_max(form.width, ft_max(form.precision + 1, 11));
	form.precision = ft_max(form.precision - 10, 0);
	form.width = ft_max(form.width - form.precision - 11, 0);
	if (form.flag[0] == 0 && form.flag[4] == 0)
		while (form.width-- > 0)
			ft_putchar_fd(' ', 1);
	ft_putchar_fd('-', 1);
	while (form.precision-- > 0)
		ft_putchar_fd('0', 1);
	if (form.flag[4])
		while (form.width-- > 0)
			ft_putchar_fd('0', 1);
	ft_putstr_fd(INTSTR, 1);
	while (form.width-- > 0)
		ft_putchar_fd(' ', 1);
}

static void	ft_3_2_1_1(t_form form, int *cnt, int *ct)
{
	ct[4] = (ct[0] < 0 || form.flag[1] || form.flag[2]) ? 1 : 0;
	(*cnt) += ft_max(form.width, ft_max(form.precision, ct[2]) + ct[4]);
	form.precision = ft_max(form.precision - ct[2], 0);
	form.width = ft_max(form.width - form.precision - (ct[2] + ct[4]), 0);
	if (form.flag[0] == 0 && form.flag[4] == 0)
		while (form.width-- > 0)
			ft_putchar_fd(' ', 1);
	if (ct[0] < 0)
		ft_putchar_fd('-', 1);
	else if (form.flag[1] || form.flag[2])
		ft_putchar_fd(form.flag[1] ? '+' : ' ', 1);
	while (form.precision-- > 0)
		ft_putchar_fd('0', 1);
	if (form.flag[4])
		while (form.width-- > 0)
			ft_putchar_fd('0', 1);
	ft_putnbr_fd(ct[0] < 0 ? ct[0] * -1 : ct[0], 1);
	while (form.width-- > 0)
		ft_putchar_fd(' ', 1);
}

static void	ft_3_2_1(t_form form, int *cnt, int *ct)
{
	ct[2] = 1;
	while (ct[1] > 9 || ct[1] < -9)
	{
		ct[2]++;
		ct[1] /= 10;
	}
	if (form.precision != -1 || form.flag[0])
		form.flag[4] = 0;
	if (ct[0] == INTMIN)
		ft_3_2_1_0(form, cnt);
	else
		ft_3_2_1_1(form, cnt, ct);
}

void		ft_3_2(t_form form, va_list *arg, int *cnt)
{
	int		ct[5];
	short	x;

	x = (short)va_arg(*arg, int);
	ct[0] = (int)x;
	ct[1] = (int)x;
	if (ct[0] == 0 && form.precision == 0)
		ft_3_2_0(form, cnt);
	else
		ft_3_2_1(form, cnt, (int*)ct);
}