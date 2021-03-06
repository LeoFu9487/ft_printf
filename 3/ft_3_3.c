/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_3_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 09:53:36 by yfu               #+#    #+#             */
/*   Updated: 2021/01/26 09:53:38 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_3_3(t_form form, va_list *arg, int *cnt)
{
	long long		ct[5];
	signed char		num;

	num = (signed char)va_arg(*arg, int);
	ct[0] = (long long)num;
	ct[1] = (long long)num;
	if (ct[0] == 0LL && form.precision == 0)
		ft_3_1_0(form, cnt);
	else
		ft_3_1_1(form, cnt, (long long*)ct);
}
