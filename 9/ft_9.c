/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_9.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 09:54:11 by yfu               #+#    #+#             */
/*   Updated: 2021/01/26 09:54:12 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_9(t_form form, va_list *arg, int *cnt)
{
	if (form.length == 0)
		ft_9_0(arg, cnt);
	else if (form.length == 1)
		ft_9_1(arg, cnt);
	else if (form.length == 2)
		ft_9_2(arg, cnt);
	else if (form.length == 3)
		ft_9_3(arg, cnt);
	else
		ft_9_(arg, cnt);
}
