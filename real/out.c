#include "ft_printf.h"

void	ft_out(t_form form, va_list *arg, int *cnt)
{
	if (form.convention == 0)
		ft_0(form, arg, cnt);
	if (form.convention == 1)
		ft_1(form, arg, cnt);
	if (form.convention == 2)
		ft_2(form, arg, cnt);
	if (form.convention == 3 || form.convention == 4)
		ft_3(form, arg, cnt);
	if (form.convention == 5)
		ft_5(form, arg, cnt);
	if (form.convention == 6)
		ft_6(form, arg, cnt);
	if (form.convention == 7)
		ft_7(form, arg, cnt);
	if (form.convention == 8)
		ft_8(form, arg, cnt);
	if (form.convention == 9)
		ft_9(form, arg, cnt);
	if (form.convention == 10)
		ft_10(form, arg, cnt);
	if (form.convention == 11)
		ft_11(form, arg, cnt);
	if (form.convention == 12)
		ft_12(form, arg, cnt);
}
