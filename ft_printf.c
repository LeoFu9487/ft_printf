/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 09:53:00 by yfu               #+#    #+#             */
/*   Updated: 2021/01/26 09:53:04 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

static void	ft_do(char **str, va_list *arg, int *cnt)
{
	t_form	form;

	(*str)++;
	ft_get_form(str, arg, &form);
	ft_out(form, arg, cnt);
}

int			ft_printf(const char *input, ...)
{
	va_list	arg;
	char	*ptr;
	int		cnt;

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
