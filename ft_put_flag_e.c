#include "ft_printf.h"

static void	ft_put_flag_e_sub(int sc)
{
	ft_putchar_fd('e', 1);
	if (sc < 0)
		ft_putchar_fd('-', 1);
	else
		ft_putchar_fd('+', 1);
	sc = (sc < 0 ? -1 * sc : sc);
	if (sc < 10)
		ft_putchar_fd('0', 1);
	ft_putnbr_fd(sc, 1);
}

void	ft_put_flag_e(double num, int sc, t_form form)
{
		//put the number, consider the flag[3] and precision
	int		n[2];

	n[0] = (int)num;
	ft_putnbr_fd(n[0], 1);
	num -= (double)n[0];
	if (form.precision || form.flag[3])
		ft_putchar_fd('.', 1);
	while (form.precision-- > 0)
	{
		num *= 10.0;
		n[0] = (int)num;
		ft_putnbr_fd(n[0], 1);
		num -= (double)n[0];
	}
	ft_put_flag_e_sub(sc);
}
