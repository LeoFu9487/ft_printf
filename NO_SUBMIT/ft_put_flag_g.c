#include "../includes/ft_printf.h"

static int	ft_cnt_power(double num, t_form form)
{
	int		ct;

	ct = 0;
	if (num < 0.0)
		num *= -1.0;
	while (num >= 10.0)
	{
		num /= 10.0;
		ct++;
	}
	while (num < 1.0)
	{
		num *= 10.0;
		ct--;
	}
	ft_round_up(&num, form.precision);
	if (num >= 10.0)
	{
		num /= 10.0;
		ct++;
	}
	return (ct);
}

static void	ft_put_as_f(double num, t_form form, int *cnt)
{
	// all flags : - + ' ' # 0
	// precision is different (need to ignore, but keep . when #)
	(void)num;
	(void)form;
	(void)cnt;
}

static void	ft_put_as_e(double num, t_form form, int *cnt)
{
	(void)num;
	(void)form;
	(void)cnt;
}

void	ft_put_flag_g(double num, t_form form, int *cnt)
{
	int	n[5];

	n[0] = ft_cnt_power(num, form);
	if (n[0] < -4 || n[0] >= form.precision)
		ft_put_as_e(num, form, cnt);
	else
		ft_put_as_f(num, form, cnt);
}
