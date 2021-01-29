/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_5.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 09:53:38 by yfu               #+#    #+#             */
/*   Updated: 2021/01/26 09:53:39 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_5(t_form form, va_list *arg, int *cnt)
{
	if (form.length == 0)
		ft_5_0(form, arg, cnt);
	else if (form.length == 1)
		ft_5_1(form, arg, cnt);
	else if (form.length == 2)
		ft_5_2(form, arg, cnt);
	else if (form.length == 3)
		ft_5_3(form, arg, cnt);
	else
		ft_5_(form, arg, cnt);
}
