/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_6_.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 09:53:50 by yfu               #+#    #+#             */
/*   Updated: 2021/01/26 09:53:51 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_6_(t_form form, va_list *arg, int *cnt)
{
	unsigned long long	ct[6];
	unsigned			x;

	x = va_arg(*arg, unsigned);
	ct[0] = (unsigned long long)x;
	ct[1] = ct[0];
	if (form.precision != -1 || form.flag[0])
		form.flag[4] = 0;
	if (ct[0] == 0ULL)
		ft_6_1_0(form, cnt);
	else
		ft_6_1_1(form, cnt, (unsigned long long*)ct);
}
