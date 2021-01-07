#include "ft_printf.h"

static void ft_rec(unsigned int num, int cnt, unsigned int len, const char *base)
{
    if (cnt == 8)
        return ;
    ft_rec(num / len, cnt + 1, len, base);
    ft_putchar_fd(base[num % len], 1);
}

void        ft_itoa_base(void* num, const char *base)
{
    unsigned int     len;

    len = ft_strlen(base);
    if (len < 2)
    {
        ft_putstr_fd("ERROR_IN_ITOA_BASE\n", 1);
        return ;
    }
    ft_rec((unsigned int)num, 0, len, base);
}
