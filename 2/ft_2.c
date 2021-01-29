/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 09:53:18 by yfu               #+#    #+#             */
/*   Updated: 2021/01/26 09:53:19 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_2_sub(t_form form, void *out)
{
	if (form.flag[4])
	{
		ft_putstr_fd("0x", 1);
		while (form.width-- > 0)
			ft_putchar_fd('0', 1);
		ft_itoa_base(out, "0123456789abcdef");
	}
	else if (form.flag[0] == 0)
	{
		while (form.width-- > 0)
			ft_putchar_fd(' ', 1);
		ft_putstr_fd("0x", 1);
		while (form.precision-- > 0)
			ft_putchar_fd('0', 1);
		ft_itoa_base(out, "0123456789abcdef");
	}
	else
	{
		ft_putstr_fd("0x", 1);
		while (form.precision-- > 0)
			ft_putchar_fd('0', 1);
		ft_itoa_base(out, "0123456789abcdef");
		while (form.width-- > 0)
			ft_putchar_fd(' ', 1);
	}
}

void		ft_2_1(t_form form, int *cnt)
{
	if (form.precision == -1)
		form.precision = 1;
	form.precision = ft_max(form.precision, 0);
	(*cnt) += ft_max(form.precision + 2, form.width);
	form.width = ft_max(form.width - form.precision - 2, 0);
	if (form.flag[0] == 0 && form.flag[4] == 0)
		while (form.width-- > 0)
			ft_putchar_fd(' ', 1);
	ft_putstr_fd("0x", 1);
	if (form.flag[4])
		while (form.width-- > 0)
			ft_putchar_fd('0', 1);
	while (form.precision-- > 0)
		ft_putchar_fd('0', 1);
	while (form.width-- > 0)
		ft_putchar_fd(' ', 1);
}

void		ft_2(t_form form, va_list *arg, int *cnt)
{
	int		len;
	void	*out;

	out = va_arg(*arg, void*);
	if (form.precision != -1 || form.flag[0])
		form.flag[4] = 0;
	if (out == NULL)
	{
		ft_2_1(form, cnt);
		return ;
	}
	len = ft_get_len((unsigned long)out, 16UL);
	form.precision = ft_max(form.precision, len);
	form.width = ft_max(form.width, form.precision + 2);
	(*cnt) += form.width;
	form.width -= form.precision + 2;
	form.precision -= len;
	ft_2_sub(form, out);
}
