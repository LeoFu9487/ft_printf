/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_3_.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 09:53:28 by yfu               #+#    #+#             */
/*   Updated: 2021/01/26 09:53:29 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_3_(t_form form, va_list *arg, int *cnt)
{
	long long	ct[5];
	int			num;

	num = va_arg(*arg, int);
	ct[0] = (long long)num;
	ct[1] = (long long)num;
	if (ct[0] == 0LL && form.precision == 0)
		ft_3_1_0(form, cnt);
	else
		ft_3_1_1(form, cnt, (long long*)ct);
}
