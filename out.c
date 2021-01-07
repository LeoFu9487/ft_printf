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
    /*
    %p
    */
    /*
    flag : empty, -
    width : yes
    precision : no
    */

}
static void ft_3(t_form form, va_list *arg, int *cnt)
{
    //%d
}
static void ft_4(t_form form, va_list *arg, int *cnt)
{

}
static void ft_5(t_form form, va_list *arg, int *cnt)
{

}
static void ft_6(t_form form, va_list *arg, int *cnt)
{

}
static void ft_7(t_form form, va_list *arg, int *cnt)
{

}
static void ft_9(t_form form, va_list *arg, int *cnt)
{

}
static void ft_10(t_form form, va_list *arg, int *cnt)
{

}
static void ft_11(t_form form, va_list *arg, int *cnt)
{

}
static void ft_12(t_form form, va_list *arg, int *cnt)
{

}

void    ft_out(t_form form, va_list *arg, int *cnt)
{
    if (form.convention == 0)
        ft_0(form, arg, cnt);
    if (form.convention == 1)
        ft_1(form, arg, cnt);
    if (form.convention == 2)
        ft_2(form, arg, cnt);
    if (form.convention == 3)
        ft_3(form, arg, cnt);
    if (form.convention == 4)
        ft_4(form, arg, cnt);
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
