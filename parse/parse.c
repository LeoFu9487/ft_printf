#include "../includes/ft_printf.h"

static void	ft_init_form(t_form *form)
{
	int ct;

	ct = -1;
	while (++ct < 5)
		form->flag[ct] = 0;
	form->width = 0;
	form->length = -1;
	form->convention = -1;
	form->precision = -1;
}

static void	ft_get_flags(char **str, t_form *form)
{
	char	check[5];
	int		ct[2];

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

static void	ft_get_width(char **str, va_list *arg, t_form *form)
{
	if (**str == '*')
	{
		form->width = va_arg(*arg, int);
		if (form->width < 0)
		{
			(form->width) *= -1;
			(form->flag[0])++;
		}
		(*str)++;
	}
	else
	{
		form->width = ft_atoi(*str);
		while (**str >= '0' && **str <= '9')
			(*str)++;
	}
}

static void	ft_get_precision(char **str, va_list *arg, t_form *form)
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

void		ft_get_form(char **str, va_list *arg, t_form *form)
{
	ft_init_form(form);
	ft_get_flags(str, form);
	ft_get_width(str, arg, form);
	ft_get_precision(str, arg, form);
	ft_get_form_length(str, form);
	ft_get_convention(str, form);
}
