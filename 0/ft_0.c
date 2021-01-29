/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_0.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 09:53:09 by yfu               #+#    #+#             */
/*   Updated: 2021/01/26 09:53:10 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_0_(t_form form, va_list *arg, int *cnt)
{
	if (form.width > 1 && form.flag[0] == 0)
	{
		(*cnt) += form.width;
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

void		ft_0(t_form form, va_list *arg, int *cnt)
{
	if (form.length == 0)
		ft_0_0(form, arg, cnt);
	else
		ft_0_(form, arg, cnt);
}
