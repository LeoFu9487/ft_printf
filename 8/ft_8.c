/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_8.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 09:54:09 by yfu               #+#    #+#             */
/*   Updated: 2021/01/26 09:54:10 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_8(t_form form, int *cnt)
{
	form.width = (form.width < 1 ? 1 : form.width);
	(*cnt) += form.width;
	if (!form.flag[0])
	{
		while (form.width-- > 1)
		{
			if (form.flag[4])
				ft_putchar_fd('0', 1);
			else
				ft_putchar_fd(' ', 1);
		}
	}
	ft_putchar_fd('%', 1);
	if (form.flag[0])
	{
		while (form.width-- > 1)
			ft_putchar_fd(' ', 1);
	}
}
