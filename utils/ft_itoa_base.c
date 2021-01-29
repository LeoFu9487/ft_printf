/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 09:56:40 by yfu               #+#    #+#             */
/*   Updated: 2021/01/26 09:56:41 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_rec(unsigned long num, unsigned int len, const char *base)
{
	if (num >= len)
		ft_rec(num / len, len, base);
	ft_putchar_fd(base[num % len], 1);
}

void		ft_itoa_base(void *num, const char *base)
{
	unsigned int	len;

	len = ft_strlen(base);
	if (len < 2)
	{
		ft_putstr_fd("ERROR_IN_ITOA_BASE\n", 1);
		return ;
	}
	ft_rec((unsigned long)num, len, base);
}

int			ft_get_len(unsigned long num, unsigned long base_len)
{
	return (num < base_len ? 1 : 1 + ft_get_len(num / base_len, base_len));
}
