/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_6.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 09:53:48 by yfu               #+#    #+#             */
/*   Updated: 2021/01/26 09:53:50 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_6(t_form form, va_list *arg, int *cnt)
{
	if (form.length == 0)
		ft_6_0(form, arg, cnt);
	else if (form.length == 1)
		ft_6_1(form, arg, cnt);
	else if (form.length == 2)
		ft_6_2(form, arg, cnt);
	else if (form.length == 3)
		ft_6_3(form, arg, cnt);
	else
		ft_6_(form, arg, cnt);
}
