#include "../includes/ft_printf.h"

//not finished yet
void	ft_5_(t_form form, va_list *arg, int *cnt)
{
	unsigned long long int   ct[4];

	ct[1] = ct[0] = va_arg(*arg, unsigned long long int);
	if (ct[0] == 0ULL && form.precision == 0)
	{
		(*cnt) += form.width;
		while ((form.width)-- > 0)
			ft_putchar_fd(' ', 1);
		return ;
	}
	ct[2] = 1ULL;
	while (ct[1] > 9ULL)
	{
		ct[2]++;
		ct[1] /= 10ULL;
	}
	if (form.precision != -1)
		form.flag[4] = 0;
	if (form.width > (int)ct[2] && form.width > form.precision)
	{
		(*cnt) += form.width;
		if (form.flag[0])
		{
			ft_putull(ct[0], form);
			while (form.width > (int)ct[2] && form.width > form.precision)
			{
				form.width--;
				ft_putchar_fd(' ', 1);
			}
		}
		else if (form.flag[4])
		{
			while (form.width > (int)ct[2] && form.width > form.precision)
			{
				ft_putchar_fd('0', 1);
				form.width--;
			}
			ft_putull(ct[0], form);
		}
		else
		{
			while (form.width > (int)ct[2] && form.width > form.precision)
			{
				ft_putchar_fd(' ', 1);
				form.width--;
			}
			ft_putull(ct[0], form);
		}
	}
	else
	{
		(*cnt) += ft_putull(ct[0], form);
	}
}
