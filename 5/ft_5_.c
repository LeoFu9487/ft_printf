#include "../includes/ft_printf.h"

void		ft_5_(t_form form, va_list *arg, int *cnt)
{
	unsigned long long	ct[5];

	ct[0] = (unsigned long long)va_arg(*arg, unsigned int);
	ct[1] = ct[0];
	if (ct[0] == 0ULL && form.precision == 0)
		ft_5_1_0(form, cnt);
	else
		ft_5_1_1(form, cnt, (unsigned long long*)ct);
}
