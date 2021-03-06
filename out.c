/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 09:53:05 by yfu               #+#    #+#             */
/*   Updated: 2021/01/26 09:53:08 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

void	ft_out(t_form form, va_list *arg, int *cnt)
{
	if (form.convention == 0)
		ft_0(form, arg, cnt);
	if (form.convention == 1)
		ft_1(form, arg, cnt);
	if (form.convention == 2)
		ft_2(form, arg, cnt);
	if (form.convention == 3 || form.convention == 4)
		ft_3(form, arg, cnt);
	if (form.convention == 5)
		ft_5(form, arg, cnt);
	if (form.convention == 6)
		ft_6(form, arg, cnt);
	if (form.convention == 7)
		ft_7(form, arg, cnt);
	if (form.convention == 8)
		ft_8(form, cnt);
	if (form.convention == 9)
		ft_9(form, arg, cnt);
	if (form.convention == 10)
		ft_10(form, arg, cnt);
}
