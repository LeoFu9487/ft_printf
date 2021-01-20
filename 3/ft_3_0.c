#include "../includes/ft_printf.h"

/*
all change
*/

static void	ft_3_0_0(t_form form, int *cnt)
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

static void	ft_3_0_1_0(t_form form, int *cnt)
{
	(*cnt) += ft_max(form.width, ft_max(form.precision + 1, 20));
	form.precision = ft_max(form.precision - 19, 0);
	form.width = ft_max(form.width - form.precision - 20, 0);
	if (form.flag[0] == 0 && form.flag[4] == 0)
		while (form.width-- > 0)
			ft_putchar_fd(' ', 1);
	ft_putchar_fd('-', 1);
	while (form.precision-- > 0)
		ft_putchar_fd('0', 1);
	if (form.flag[4])
		while (form.width-- > 0)
			ft_putchar_fd('0', 1);
	ft_putstr_fd(LSTR, 1);
	while (form.width-- > 0)
		ft_putchar_fd(' ', 1);
}

static void	ft_3_0_1_1(t_form form, int *cnt, long *ct)
{
	ct[4] = (ct[0] < 0L || form.flag[1] || form.flag[2]) ? 1L : 0L;
	(*cnt) += ft_max(form.width, ft_max(form.precision, (int)ct[2]) + (int)ct[4]);
	form.precision = ft_max(form.precision - (int)ct[2], 0);
	form.width = ft_max(form.width - form.precision - (int)(ct[2] + ct[4]), 0);
	if (form.flag[0] == 0 && form.flag[4] == 0)
		while (form.width-- > 0)
			ft_putchar_fd(' ', 1);
	if (ct[0] < 0L)
		ft_putchar_fd('-', 1);
	else if (form.flag[1] || form.flag[2])
		ft_putchar_fd(form.flag[1] ? '+' : ' ', 1);
	while (form.precision-- > 0)
		ft_putchar_fd('0', 1);
	if (form.flag[4])
		while (form.width-- > 0)
			ft_putchar_fd('0', 1);
	ft_putll((long long)ct[0]);
	while (form.width-- > 0)
		ft_putchar_fd(' ', 1);
}

static void	ft_3_0_1(t_form form, int *cnt, long *ct)
{
	ct[2] = 1L;
	while (ct[1] > 9L || ct[1] < -9L)
	{
		ct[2]++;
		ct[1] /= 10L;
	}
	if (form.precision != -1 || form.flag[0])
		form.flag[4] = 0;
	if (ct[0] == LMIN)
		ft_3_0_1_0(form, cnt);
	else
		ft_3_0_1_1(form, cnt, ct);
}

void		ft_3_0(t_form form, va_list *arg, int *cnt)
{
	long int	ct[5];

	ct[1] = ct[0] = va_arg(*arg, long int);
	if (ct[0] == 0L && form.precision == 0)
		ft_3_0_0(form, cnt);
	else
		ft_3_0_1(form, cnt, (long*)ct);
}