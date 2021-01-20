#include "../includes/ft_printf.h"

static void	ft_putll_sub(long long int num)
{
	int	out;

	if (num > 9LL)
		ft_putll_sub(num / 10LL);
	out = (int)(num % 10LL);
	ft_putnbr_fd(out, 1);
}

void		ft_putll(long long int num)
{
	if (num < 0LL)
		num *= -1LL;
	ft_putll_sub(num);
}

static void	ft_putull_sub(unsigned long long int num)
{
	int out;

	if (num > 9ULL)
		ft_putull_sub(num / 10ULL);
	out = (int)(num % 10ULL);
	ft_putnbr_fd(out, 1);
}

int	ft_putull(unsigned long long int num, t_form form)
{
	int cnt[2];
	unsigned long long int num2;

	cnt[0] = 0;
	cnt[1] = 1;
	num2 = num;
	while (num2 > 9ULL)
	{
		cnt[1]++;
		num2 /= 10ULL;
	}
	if (form.precision > cnt[1])
	{
		cnt[0] += form.precision;
		while (form.precision-- > cnt[1])
			ft_putchar_fd('0', 1);
	}
	else
		cnt[0] += cnt[1];
	ft_putull_sub(num);
	return (cnt[0]);
}
