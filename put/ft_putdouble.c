#include "../includes/ft_printf.h"

static void		ft_putdouble_sub(double num, int len)
{
	unsigned long long n;

	if (len < 0)
		return ;
	else if (len > 0)
		ft_putdouble_sub(num / 10.0, len - 1);
	n = (unsigned long long)num;
	n %= 10ULL;
	ft_putnbr_fd(n, 1);
}

static double	ft_round_up_sub(int *ct, double *n,
			unsigned long long *stack, double *num)
{
	ct[1] = 1;
	n[1] = 0.0;
	while (--ct[0] >= 0)
	{
		if (ct[1])
		{
			stack[ct[0]]++;
			if (stack[ct[0]] >= 10ULL)
			{
				if (ct[0])
					stack[ct[0]] %= 10ULL;
			}
			else
				ct[1] = 0;
		}
		n[1] /= 10.0;
		n[1] += (double)stack[ct[0]];
	}
	if (ct[2] == -1)
		n[1] *= -1.0;
	return (*num = n[1]);
}

double			ft_round_up(double *num, int precision)
{
	double				n[2];
	unsigned long long	stack[350];
	int					ct[3];

	ct[2] = 1;
	if (*num < 0.0)
		ct[2] *= -1;
	(*num) = (*num) < 0.0 ? (*num) * -1.0 : (*num);
	n[0] = *num;
	stack[0] = (unsigned long long)n[0];
	n[0] -= (double)stack[0];
	ct[0] = 1;
	while (ct[0] <= precision + 1 && ct[0] < 350)
	{
		n[0] *= 10.0;
		stack[ct[0]] = (unsigned long long)n[0];
		n[0] -= (double)stack[ct[0]];
		ct[0]++;
	}
	ct[0]--;
	if (stack[ct[0]] <= 4ULL && ct[2] == -1)
		(*num) *= -1.0;
	return (stack[ct[0]] <= 4ULL ? (*num) : ft_round_up_sub((int*)ct,
	(double*)n, (unsigned long long*)stack, (double *)num));
}

void			ft_putdouble(double num, t_form form, int len)
{
	unsigned long long use;

	ft_putdouble_sub(num, len - 1);
	if (form.precision == 0)
	{
		if (form.flag[3])
			ft_putchar_fd('.', 1);
		return ;
	}
	ft_putchar_fd('.', 1);
	use = (unsigned long long)num;
	num -= (double)use;
	while ((form.precision--) > 0)
	{
		num *= 10.0;
		use = (unsigned long long)num;
		ft_putnbr_fd((int)use, 1);
		num -= (double)use;
	}
}
