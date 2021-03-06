/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 09:53:21 by yfu               #+#    #+#             */
/*   Updated: 2021/01/26 09:53:27 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_3(t_form form, va_list *arg, int *cnt)
{
	if (form.length == 0)
		ft_3_0(form, arg, cnt);
	else if (form.length == 1)
		ft_3_1(form, arg, cnt);
	else if (form.length == 2)
		ft_3_2(form, arg, cnt);
	else if (form.length == 3)
		ft_3_3(form, arg, cnt);
	else
		ft_3_(form, arg, cnt);
}
