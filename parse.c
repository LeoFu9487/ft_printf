#include "ft_printf.h"

static void    ft_init_form(t_form *form)
{
    int ct;

    ct = -1;
    while (++ct < 5)
        form->flag[ct] = 0;
    form->width = 0;
    form->length = 0;
    form->convention = -1;
    form->precision = -1;
}

static void    ft_get_flags(char **str, t_form *form)
{
    char    check[5];
    int     ct[2];

    check[0] = '-';
    check[1] = '+';
    check[2] = ' ';
    check[3] = '#';
    check[4] = '0';
    while (**str)
    {
        ct[0] = -1;
        ct[1] = 1;
        while (++ct[0] < 5)
        {
            if (**str == check[ct[0]])
            {
                form->flag[ct[0]]++;
                ct[1] = 0;
                break ;
            }
        }
        if (ct[1])
            break ;
        (*str)++;
    }
}

static void ft_get_width(char **str, va_list *arg, t_form *form)
{
    if (**str == '*')
    {
        form->width = va_arg(*arg, int);
        (*str)++;
    }
    else
    {
        form->width = ft_atoi(*str);
        while (**str >= '0' && **str <= '9')
            (*str)++;
    }
}

static void ft_get_precision(char **str, va_list *arg, t_form *form)
{
    if (**str != '.')
        return ;
    (*str)++;
    if (**str == '*')
    {
        form->precision = va_arg(*arg, int);
        (*str)++;
    }
    else
    {
        form->precision = ft_atoi(*str);
        while (**str >= '0' && **str <= '9')
            (*str)++;
    }
}

static void ft_get_length(char **str, t_form *form)
{
    if (**str == 'l')
    {
        (*str)++;
        if (**str == 'l')
        {
            form->length = 1;
            (*str)++;
        }
        else
            form->length = 0;
    }
    else if (**str == 'h')
    {
        (*str)++;
        if (**str == 'h')
        {
            form->length = 3;
            (*str)++;
        }
        else
            form->length = 2;
    }
}

void    ft_get_convention(char **str, t_form *form)
{
    char    check[13];
    int     ct;

    check[0] = 'c';
    check[1] = 's';
    check[2] = 'p';
    check[3] = 'd';
    check[4] = 'i';
    check[5] = 'u';
    check[6] = 'x';
    check[7] = 'X';
    check[8] = '%';
    check[9] = 'n';
    check[10] = 'f';
    check[11] = 'g';
    check[12] = 'e';
    ct = -1;
    while (++ct < 13)
        if (**str == check[ct])
        {
            form->convention = ct;
            (*str)++;
            return ;
        }
}

void    ft_get_form(char **str, va_list *arg, t_form *form)
{
    ft_init_form(form);
    ft_get_flags(str, form);
    ft_get_width(str, arg, form);
    ft_get_precision(str, arg, form);
    ft_get_length(str, form);
    ft_get_convention(str, form);
}

/*


    cspdiuxX%nf g e
    0123456789101112



    [flags][width][.precision][length]specifier


    flags : '-' '+' ' ' '#' '0'
    when there is + and ' ', ignore ' '
    when there is - ignore 0 (only for left pad 0's)
    width: number *
    precision : .number .*
    default -1
    length : l ll h hh
             0  1 2  3

    convention :
    cspdiuxX%nf g e
    0123456789101112



*/
