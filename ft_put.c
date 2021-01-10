#include "ft_printf.h"

static void    ft_putll_sub(long long int num)
{
    int out;

    if (num > 9LL)
        ft_putll_sub(num / 10LL);
    out = (int)(num % 10LL);
    ft_putnbr_fd(out, 1);
}

int    ft_putll(long long int num, t_form form)
{
    int cnt[2];
    long long int num2;

    if (num < 0LL)
    {
        ft_putendl_fd("ERROR_IN_FT_PUTLL", 1);
        return (0);
    }
    cnt[0] = 0;
    cnt[1] = 1;
    num2 = num;
    while (num2 > 9LL)
    {
        cnt[1]++;
        num2 /= 10LL;
    }
    if (form.precision > cnt[1])
    {
        cnt[0] += form.precision;
        while (form.precision-- > cnt[1])
            ft_putchar_fd('0', 1);
    }
    else
        cnt[0] += cnt[1];
    ft_putll_sub(num);
    return (cnt[0]);
}

static void    ft_putull_sub(unsigned long long int num)
{
    int out;

    if (num > 9ULL)
        ft_putull_sub(num / 10ULL);
    out = (int)(num % 10ULL);
    ft_putnbr_fd(out, 1);
}

int    ft_putull(unsigned long long int num, t_form form)
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

static void ft_putdouble_sub(double num, int len)
{
}

void    ft_putdouble(double num, t_form form, int len)
{
    double ct[1];

    //len means how many digits before decimal point

     // care about precision and flag[3]
     //round up
}
