#include "../includes/ft_printf.h"

static void ft_rec(unsigned long num, int cnt, unsigned int len, const char *base)
{
	if (cnt == 8)
		return ;
	ft_rec(num / len, cnt + 1, len, base);
	ft_putchar_fd(base[num % len], 1);
}

void 	   ft_itoa_base(void* num, const char *base)
{
	unsigned int	 len;

	len = ft_strlen(base);
	if (len < 2)
	{
		ft_putstr_fd("ERROR_IN_ITOA_BASE\n", 1);
		return ;
	}
	ft_rec((unsigned long)num, 0, len, base);
}

static void ft_rec_ull(unsigned long long num, const char *base, unsigned long long len)
{
	if (num >= len)
		ft_rec_ull(num / len, base, len);
	ft_putchar_fd((int)base[(num % len)], 1);
}

void 	   ft_itoa_base_ull(unsigned long long num, const char *base)
{
	unsigned long long len;

	len = (unsigned long long)ft_strlen(base);
	if (len < 2ULL)
	{
		ft_putstr_fd("ERROR_IN_ITOA_BASE_ULL\n", 1);
		return ;
	}
	ft_rec_ull(num, base, len);
}
