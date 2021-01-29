/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 09:53:12 by yfu               #+#    #+#             */
/*   Updated: 2021/01/26 10:39:44 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_1_(t_form form, va_list *arg, int *cnt)
{
	char	*out;

	out = va_arg(*arg, char*);
	out = (out ? out : "(null)");
	if (form.precision == -1)
		form.precision = (int)ft_strlen(out);
	else if (form.precision > (int)ft_strlen(out))
		form.precision = (int)ft_strlen(out);
	form.width = (form.width > form.precision ? form.width : form.precision);
	(*cnt) += form.width;
	form.width -= form.precision;
	if (form.flag[0] == 0)
		while (form.width-- > 0)
			ft_putchar_fd(form.flag[4] ? '0' : ' ', 1);
	while (form.precision-- > 0)
		ft_putchar_fd(*(out++), 1);
	while (form.width-- > 0)
		ft_putchar_fd(' ', 1);
}

void		ft_1(t_form form, va_list *arg, int *cnt)
{
	if (form.precision != -1 || form.flag[0])
		form.flag[4] = 0;
	if (form.length == 0)
		ft_1_0(form, arg, cnt);
	else
		ft_1_(form, arg, cnt);
}
