/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_7_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 09:54:05 by yfu               #+#    #+#             */
/*   Updated: 2021/01/26 09:54:06 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_7_2(t_form form, va_list *arg, int *cnt)
{
	unsigned long long	ct[6];
	unsigned short		x;

	x = (unsigned short)va_arg(*arg, unsigned);
	ct[0] = (unsigned long long)x;
	ct[1] = ct[0];
	if (form.precision != -1 || form.flag[0])
		form.flag[4] = 0;
	if (ct[0] == 0ULL)
		ft_7_1_0(form, cnt);
	else
		ft_7_1_1(form, cnt, (unsigned long long*)ct);
}
