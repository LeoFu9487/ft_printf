#include "../includes/ft_printf.h"

void		ft_5_1_0(t_form form, int *cnt)
{
	(*cnt) += ft_max(0, form.width);
	if (form.flag[0] == 0)
		while (form.width-- > 0)
			ft_putchar_fd(' ', 1);
	while (form.width-- > 0)
		ft_putchar_fd(' ', 1);
}

static void	ft_5_1_1_0(t_form form, int *cnt, unsigned long long *ct)
{
	(*cnt) += ft_max(form.width, ft_max(form.precision, (int)ct[2]));
	form.precision = ft_max(form.precision - (int)ct[2], 0);
	form.width = ft_max(form.width - form.precision - (int)(ct[2]), 0);
	if (form.flag[0] == 0 && form.flag[4] == 0)
		while (form.width-- > 0)
			ft_putchar_fd(' ', 1);
	while (form.precision-- > 0)
		ft_putchar_fd('0', 1);
	if (form.flag[4])
		while (form.width-- > 0)
			ft_putchar_fd('0', 1);
	ft_putull(ct[0]);
	while (form.width-- > 0)
		ft_putchar_fd(' ', 1);
}

void		ft_5_1_1(t_form form, int *cnt, unsigned long long *ct)
{
	ct[2] = 1ULL;
	while (ct[1] > 9ULL)
	{
		ct[2]++;
		ct[1] /= 10ULL;
	}
	if (form.precision != -1 || form.flag[0])
		form.flag[4] = 0;
	ft_5_1_1_0(form, cnt, ct);
}

void		ft_5_1(t_form form, va_list *arg, int *cnt)
{
	unsigned long long	ct[5];

	ct[0] = va_arg(*arg, unsigned long long);
	ct[1] = ct[0];
	if (ct[0] == 0ULL && form.precision == 0)
		ft_5_1_0(form, cnt);
	else
		ft_5_1_1(form, cnt, (unsigned long long*)ct);
}
