#include "../includes/ft_printf.h"

void		ft_5_3(t_form form, va_list *arg, int *cnt)
{
	unsigned long long	ct[5];
	unsigned char		x;

	x = (unsigned char)va_arg(*arg, unsigned int);
	ct[1] = ct[0] = (unsigned long long)x;
	if (ct[0] == 0ULL && form.precision == 0)
		ft_5_1_0(form, cnt);
	else
		ft_5_1_1(form, cnt, (unsigned long long*)ct);
}
