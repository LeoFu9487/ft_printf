#include "../includes/ft_printf.h"

void		ft_7_1_0(t_form form, int *cnt)
{
	form.precision = (form.precision == -1 ? 1 : form.precision);
	(*cnt) += ft_max(0, ft_max(form.width, form.precision));
	form.precision = ft_max(form.precision, 0);
	form.width = ft_max(form.width - form.precision, 0);
	if (form.flag[0] == 0 && form.flag[4] == 0)
		while (form.width-- > 0)
			ft_putchar_fd(' ', 1);
	if (form.flag[4])
		while (form.width-- > 0)
			ft_putchar_fd('0', 1);
	while (form.precision-- > 0)
		ft_putchar_fd('0', 1);
	while (form.width-- > 0)
		ft_putchar_fd(' ', 1);
}

static void	ft_7_1_1_0(t_form form, int *cnt, unsigned long long *ct)
{
	ct[4] = (form.flag[3] ? 2ULL : 0ULL);
	(*cnt) += ft_max(form.width, ft_max(form.precision, (int)ct[2])
												+ (int)ct[4]);
	form.precision = ft_max(form.precision - (int)ct[2], 0);
	form.width = ft_max(form.width - form.precision - (int)(ct[2] + ct[4]), 0);
	if (form.flag[0] == 0 && form.flag[4] == 0)
		while (form.width-- > 0)
			ft_putchar_fd(' ', 1);
	if (form.flag[3])
		ft_putstr_fd("0X", 1);
	if (form.flag[4])
		while (form.width-- > 0)
			ft_putchar_fd('0', 1);
	while (form.precision-- > 0)
		ft_putchar_fd('0', 1);
	ft_itoa_base_ull(ct[0], "0123456789ABCDEF");
	while (form.width-- > 0)
		ft_putchar_fd(' ', 1);
}

void		ft_7_1_1(t_form form, int *cnt, unsigned long long *ct)
{
	ct[2] = 1ULL;
	while (ct[1] > 15ULL)
	{
		ct[2]++;
		ct[1] /= 16ULL;
	}
	ft_7_1_1_0(form, cnt, ct);
}

void		ft_7_1(t_form form, va_list *arg, int *cnt)
{
	unsigned long long	ct[6];

	ct[0] = va_arg(*arg, unsigned long long);
	ct[1] = ct[0];
	if (form.precision != -1 || form.flag[0])
		form.flag[4] = 0;
	if (ct[0] == 0ULL)
		ft_7_1_0(form, cnt);
	else
		ft_7_1_1(form, cnt, (unsigned long long*)ct);
}
