#include "../includes/ft_printf.h"

void		ft_3_0(t_form form, va_list *arg, int *cnt)
{
	long long	ct[5];
	long		num;

	num = va_arg(*arg, long);
	ct[0] = (long long)num;
	ct[1] = (long long)num;
	if (ct[0] == 0LL && form.precision == 0)
		ft_3_1_0(form, cnt);
	else
		ft_3_1_1(form, cnt, (long long*)ct);
}
