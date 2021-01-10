#include "ft_printf.h"

/*
flags : '-' '+' ' ' '#' '0'
    when there is + and ' ', ignore ' '
    when there is - ignore 0 (only for left pad 0's)
    width: number *
    precision : .number .*
    default 0
    length : l ll h hh
             0  1 2  3
    convention :
    cspdiuxX%nf g e
    0123456789101112
*/
static void ft_0(t_form form, va_list *arg, int *cnt)
{
    /*
    c
    length 0 not finished yet
    */
    if (form.width > 1 && form.flag[0] == 0)
    {
        (*cnt) += form.width;
        if (form.flag[4])
            while ((form.width)-- > 1)
                ft_putchar_fd('0', 1);
        else
            while ((form.width)-- > 1)
                ft_putchar_fd(' ', 1);
        ft_putchar_fd(va_arg(*arg, int), 1);
    }
    else
    {
        ft_putchar_fd(va_arg(*arg, int), 1);
        if (form.width > 1)
        {
            (*cnt) += form.width;
            while ((form.width)-- > 1)
            ft_putchar_fd(' ', 1);
        }
        else
            (*cnt)++;
    }
}
static void ft_1(t_form form, va_list *arg, int *cnt)
{
    char    *out;
    int     len;

    /*
    s
    length 0 not finished yet
    */
    if (form.precision != -1)
        out = ft_substr(va_arg(*arg, char*), 0, form.precision);
    else
        out = ft_strdup(va_arg(*arg, char*));
    len = ft_strlen(out);
    if (form.width > len)
    {
        (*cnt) += form.width;
        if (form.flag[0] == 0)
        {
            if (form.flag[4])
                while (form.width-- > len)
                    ft_putchar_fd('0', 1);
            else
                while (form.width-- > len)
                    ft_putchar_fd(' ', 1);
        }
        ft_putstr_fd(out, 1);
        if (form.flag[0])
            while (form.width-- > len)
                ft_putchar_fd(' ', 1);
        return ;
    }
    (*cnt) += len;
    ft_putstr_fd(out, 1);
    free(out);
}
static void ft_2(t_form form, va_list *arg, int *cnt)
{
    // p
    if (form.width > 8)
    {
        (*cnt) += form.width;
        if (form.flag[0])
        {
            ft_itoa_base(va_arg(*arg, void*), "0123456789ABCDEF");
            while (form.width-- > 8)
                ft_putchar_fd(' ', 1);
        }
        else
        {
            while (form.width-- > 8)
                ft_putchar_fd(' ', 1);
            ft_itoa_base(va_arg(*arg, void*), "0123456789ABCDEF");
        }
    }
    else
    {
        (*cnt) += 8;
        ft_itoa_base(va_arg(*arg, void*), "0123456789ABCDEF");
    }
}

static void ft_3_0(t_form form, va_list *arg, int *cnt)
{
    //ld
}

static void ft_3_1(t_form form, va_list *arg, int *cnt)
{
    /*
    problem : +, - , ' '(sign) should be the first
    deal with LLONG_MIN separately
    deal with 0 separately
    -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
    if left pad 0 then sign before 0
    if left pad ' ' then ' ' before sign
    */
    //lld
    long long int   ct[4];

    ct[1] = ct[0] = va_arg(*arg, long long int);
    if (ct[0] == 0LL && form.precision == 0)
    {
        if (form.flag[0])
        {
            if (form.flag[1])
            {
                ft_putchar_fd('+', 1);
                (*cnt)++;
                (form.width)--;
            }
            else if (form.flag[2])
            {
                ft_putchar_fd(' ', 1);
                (*cnt)++;
                (form.width)--;
            }
            if (form.width > 0)
                (*cnt) += form.width;
            while ((form.width)-- > 0)
                ft_putchar_fd(' ', 1);
        }
        else
        {
            if (form.flag[1] || form.flag[2])
            {
                (*cnt)++;
                (form.width)--;
            }
            if (form.width > 0)
                (*cnt) += form.width;
            while ((form.width)-- > 0)
                ft_putchar_fd(' ', 1);
            if (form.flag[1])
                ft_putchar_fd('+', 1);
            else if (form.flag[2])
                ft_putchar_fd(' ', 1);
        }
        return ;
    }
    ct[2] = 1LL;
    while (ct[1] > 9LL || ct[1] < -9LL)
    {
        ct[2]++;
        ct[1] /= 10LL;
    }


    if (form.precision != -1)
        form.flag[4] = 0;
    if (ct[0] < 0LL)
    {
        form.precision++;
        if (ct[0] == -9223372036854775808LL)
        {
            if (form.width > 20 && form.width > form.precision)
            {
                (*cnt) += form.width;
                if (form.flag[0])
                {
                    ft_putchar_fd('-', 1);
                    ct[3] = (long long int)form.precision;
                    while (ct[3]-- > 20)
                        ft_putchar_fd('0', 1);
                    ft_putstr_fd("9223372036854775808", 1);
                    while (form.width > 20 && form.width > form.precision)
                    {
                        ft_putchar_fd(' ', 1);
                        form.width--;
                    }
                }
                else if (form.flag[4])
                {
                    //sign, left pad 0
                    ft_putchar_fd('-', 1);
                    while (form.width > 20 && form.width > form.precision)
                    {
                        ft_putchar_fd('0', 1);
                        form.width--;
                    }
                    ft_putstr_fd("9223372036854775808", 1);
                }
                else
                {
                    //left pad ' ', sign
                    while (form.width > 20 && form.width > form.precision)
                    {
                        ft_putchar_fd(' ', 1);
                        form.width--;
                    }
                    ft_putchar_fd('-', 1);
                    while ((form.precision)-- > 20)
                        ft_putchar_fd('0', 1);
                    ft_putstr_fd("9223372036854775808", 1);
                }
            }
            else if (form.precision > 20)
            {
                (*cnt) += form.precision;
                ft_putchar_fd('-', 1);
                while (form.precision-- > 20)
                    ft_putchar_fd('0', 1);
                ft_putstr_fd("9223372036854775808", 1);
            }
            else
            {
                (*cnt) += 20;
                ft_putstr_fd("-9223372036854775808", 1);
            }
            return ;
        }
        else
            ct[0] *= -1LL;
        (form.precision)--;
        (form.width)--;
        if (form.width > (int)ct[2] && form.width > form.precision)
        {
            (*cnt) += form.width + 1;
            if (form.flag[0])
            {
                ft_putchar_fd('-', 1);
                ft_putll(ct[0], form);
                while (form.width > (int)ct[2] && form.width > form.precision)
                {
                    form.width--;
                    ft_putchar_fd(' ', 1);
                }
            }
            else if (form.flag[4])
            {
                ft_putchar_fd('-', 1);
                while (form.width > (int)ct[2] && form.width > form.precision)
                {
                    ft_putchar_fd('0', 1);
                    form.width--;
                }
                ft_putll(ct[0], form);
            }
            else
            {
                while (form.width > (int)ct[2] && form.width > form.precision)
                {
                    ft_putchar_fd(' ', 1);
                    form.width--;
                }
                ft_putchar_fd('-', 1);
                ft_putll(ct[0], form);
            }
        }
        else
        {
            ft_putchar_fd('-', 1);
            (*cnt) += ft_putll(ct[0], form) + 1;
        }
        return ;
    }
    if (form.width > (int)ct[2] && form.width > form.precision)
    {
        (*cnt) += form.width;
        if (form.flag[0])
        {
            if (form.flag[1])
            {
                ft_putchar_fd('+', 1);
                form.width--;
            }
            else if (form.flag[2])
            {
                ft_putchar_fd(' ', 1);
                form.width--;
            }
            ft_putll(ct[0], form);
            while (form.width > (int)ct[2] && form.width > form.precision)
            {
                form.width--;
                ft_putchar_fd(' ', 1);
            }
        }
        else if (form.flag[4])
        {
            if (form.flag[1])
            {
                ft_putchar_fd('+', 1);
                form.width--;
            }
            else if (form.flag[2])
            {
                ft_putchar_fd(' ', 1);
                form.width--;
            }
            while (form.width > (int)ct[2] && form.width > form.precision)
            {
                ft_putchar_fd('0', 1);
                form.width--;
            }
            ft_putll(ct[0], form);
        }
        else
        {
            if (form.flag[1] || form.flag[2])
                form.width--;
            while (form.width > (int)ct[2] && form.width > form.precision)
            {
                ft_putchar_fd(' ', 1);
                form.width--;
            }
            if (form.flag[1])
                ft_putchar_fd('+', 1);
            else if (form.flag[2])
                ft_putchar_fd(' ', 1);
            ft_putll(ct[0], form);
        }
    }
    else
    {
        //no width
        if (form.flag[1])
        {
            ft_putchar_fd('+', 1);
            (*cnt)++;
        }

        else if (form.flag[2])
        {
            (*cnt)++;
            ft_putchar_fd(' ', 1);
        }
        (*cnt) += ft_putll(ct[0], form);
    }
}

static void ft_3_2(t_form form, va_list *arg, int *cnt)
{
    //hd
}

static void ft_3_3(t_form form, va_list *arg, int *cnt)
{
    //hhd
}

static void ft_3_(t_form form, va_list *arg, int *cnt)
{
    //d
}

static void ft_3(t_form form, va_list *arg, int *cnt)
{
    //%d
    /*
    flags : - + ' ' 0 (0 1 2 4), ignore 0 while -,0 ignore ' ' while + ' '
    width : yes
    precision : yes
    length : yes
    */
    /*
    length -> precision -> flags + width
    */
    if (form.length == 0)
        ft_3_0(form, arg, cnt);
    else if (form.length == 1)
        ft_3_1(form, arg, cnt);
    else if (form.length == 2)
        ft_3_2(form, arg, cnt);
    else if (form.length == 3)
        ft_3_3(form, arg, cnt);
    else
        ft_3_(form, arg, cnt);
}
static void ft_5(t_form form, va_list *arg, int *cnt)
{
    //u
}
static void ft_6(t_form form, va_list *arg, int *cnt)
{
    //x
}
static void ft_7(t_form form, va_list *arg, int *cnt)
{
    //X
}
static void ft_9(t_form form, va_list *arg, int *cnt)
{
    //n
}
static void ft_10(t_form form, va_list *arg, int *cnt)
{
    //f
}
static void ft_11(t_form form, va_list *arg, int *cnt)
{
    //g
}
static void ft_12(t_form form, va_list *arg, int *cnt)
{
    //e
}

void    ft_out(t_form form, va_list *arg, int *cnt)
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
        ft_putchar_fd('%', 1);
    if (form.convention == 9)
        ft_9(form, arg, cnt);
    if (form.convention == 10)
        ft_10(form, arg, cnt);
    if (form.convention == 11)
        ft_11(form, arg, cnt);
    if (form.convention == 12)
        ft_12(form, arg, cnt);
}
