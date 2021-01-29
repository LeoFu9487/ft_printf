/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_0_0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 09:53:11 by yfu               #+#    #+#             */
/*   Updated: 2021/01/26 09:53:12 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		ft_cnt(unsigned int num)
{
	if (num <= 0x7F)
		return (1);
	else if (num >= 0x80 && num <= 0x7FF)
		return (2);
	else if (num >= 0x800 && num <= 0xFFFF)
		return (3);
	else if (num >= 0x10000 && num <= 0x10FFFF)
		return (4);
	return (0);
}

static void		ft_put(unsigned int num)
{
	unsigned char	arr[4];

	if (num <= 0x7F)
		write(1, &num, 1);
	else if (num >= 0x80 && num <= 0x7FF)
	{
		arr[0] = ((num & 0xFC0) >> 6) | 0xC0;
		arr[1] = (num & 0x3F) | 0x80;
		write(1, arr, 2);
	}
	else if (num >= 0x800 && num <= 0xFFFF)
	{
		arr[0] = ((num & 0x3F000) >> 12) | 0xE0;
		arr[1] = ((num & 0xFC0) >> 6) | 0x80;
		arr[2] = (num & 0x3F) | 0x80;
		write(1, arr, 3);
	}
	else if (num >= 0x10000 && num <= 0x10FFFF)
	{
		arr[0] = ((num & 0x1C0000) >> 18) | 0xF0;
		arr[1] = ((num & 0x3F000) >> 12) | 0x80;
		arr[2] = ((num & 0xFC0) >> 6) | 0x80;
		arr[3] = (num & 0x3F) | 0x80;
		write(1, arr, 4);
	}
}

void			ft_0_0(t_form form, va_list *arg, int *cnt)
{
	int	num[2];

	num[0] = va_arg(*arg, int);
	num[1] = ft_cnt((unsigned int)num[0]);
	(*cnt) += ft_max(form.width, num[1]);
	form.width = ft_max(0, form.width - num[1]);
	if (form.flag[0] == 0)
		while (form.width-- > 0)
			ft_putchar_fd(' ', 1);
	ft_put(((unsigned int)num[0]));
	while (form.width-- > 0)
		ft_putchar_fd(' ', 1);
}
