/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 09:55:09 by yfu               #+#    #+#             */
/*   Updated: 2021/01/26 09:55:48 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_putll_sub(long long int num)
{
	int	out;

	if (num > 9LL)
		ft_putll_sub(num / 10LL);
	out = (int)(num % 10LL);
	ft_putnbr_fd(out, 1);
}

void		ft_putll(long long int num)
{
	if (num < 0LL)
		num *= -1LL;
	ft_putll_sub(num);
}

static void	ft_putull_sub(unsigned long long int num)
{
	int out;

	if (num > 9ULL)
		ft_putull_sub(num / 10ULL);
	out = (int)(num % 10ULL);
	ft_putnbr_fd(out, 1);
}

void		ft_putull(unsigned long long int num)
{
	ft_putull_sub(num);
}

void		ft_putwchar(wchar_t num)
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
