#include "ft_printf.h"

/*
static void print_form(t_form *form)
{

    for(int i = 0 ; i< 5 ; i++)
    {
        printf("flag %d : %d\n", i, form->flag[i]);
    }
    printf("width : %d\n", form->width);
    printf("precision : %d\n", form->precision);
    printf("length : %d\n", form->length);
    printf("convention : %d\n", form->convention);
}
*/
static void    ft_do(char **str, va_list *arg, int *cnt)
{
    t_form  form;
    /*
    the first %
    */
    (*str)++;
    ft_get_form(str, arg, &form);
    ft_out(form, arg, cnt);
}

int     ft_printf(const char *input, ...)
{
    va_list arg;
    char    *ptr;
    int     cnt;

    cnt = 0;
    va_start(arg, input);
    ptr = (char*)input;
    while (*ptr)
    {
        if (*ptr == '%')
            ft_do(&ptr, &arg, &cnt);

        else
        {
            cnt++;
            ft_putchar_fd(*(ptr++), 1);
        }
    }

    va_end(arg);
    return (cnt);
}

/*
deal with error or undefined behavior ?
*/
