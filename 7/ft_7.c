/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_7.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 09:54:00 by yfu               #+#    #+#             */
/*   Updated: 2021/01/26 09:54:01 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_7(t_form form, va_list *arg, int *cnt)
{
	if (form.length == 0)
		ft_7_0(form, arg, cnt);
	else if (form.length == 1)
		ft_7_1(form, arg, cnt);
	else if (form.length == 2)
		ft_7_2(form, arg, cnt);
	else if (form.length == 3)
		ft_7_3(form, arg, cnt);
	else
		ft_7_(form, arg, cnt);
}
