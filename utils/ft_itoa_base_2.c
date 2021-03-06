/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 09:55:13 by yfu               #+#    #+#             */
/*   Updated: 2021/01/26 09:55:58 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_rec_ull(unsigned long long num,
	const char *base, unsigned long long len)
{
	if (num >= len)
		ft_rec_ull(num / len, base, len);
	ft_putchar_fd((int)base[(num % len)], 1);
}

void		ft_itoa_base_ull(unsigned long long num, const char *base)
{
	unsigned long long	len;

	len = (unsigned long long)ft_strlen(base);
	if (len < 2ULL)
	{
		ft_putstr_fd("ERROR_IN_ITOA_BASE_ULL\n", 1);
		return ;
	}
	ft_rec_ull(num, base, len);
}
