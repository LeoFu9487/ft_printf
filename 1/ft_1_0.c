/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_1_0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 09:53:15 by yfu               #+#    #+#             */
/*   Updated: 2021/01/26 10:41:36 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_cnt(wchar_t num)
{
	if (num <= 0x7F)
		return (1);
	else if (num >= 0x80 && num <= 0x7FF)
		return (2);
	else if (num >= 0x800 && num <= 0xFFFF)
		return (3);
	else if (num >= 0x10000 && num <= 0x10FFFF)
		return (4);
	return (0);
}

static int	ft_outlen(wchar_t *out)
{
	return (*out == 0 ? 0 : ft_cnt(*out) + ft_outlen(out + 1));
}

static void	ft_1_0_fill(wchar_t *ptr)
{
	ptr[0] = '(';
	ptr[1] = 'n';
	ptr[2] = 'u';
	ptr[3] = 'l';
	ptr[4] = 'l';
	ptr[5] = ')';
	ptr[6] = 0;
}

void		ft_1_0(t_form form, va_list *arg, int *cnt)
{
	wchar_t	*out;
	wchar_t	ptr[7];

	ft_1_0_fill((wchar_t*)ptr);
	out = va_arg(*arg, wchar_t*);
	out = (out ? out : ptr);
	if (form.precision == -1)
		form.precision = ft_outlen(out);
	else if (form.precision > ft_outlen(out))
		form.precision = ft_outlen(out);
	form.width = (form.width > form.precision ? form.width : form.precision);
	(*cnt) += form.width;
	form.width -= form.precision;
	if (form.flag[0] == 0)
		while (form.width-- > 0)
			ft_putchar_fd(form.flag[4] ? '0' : ' ', 1);
	while (form.precision > 0)
	{
		ft_putwchar(*out);
		form.precision -= ft_cnt(*(out++));
	}
	while (form.width-- > 0)
		ft_putchar_fd(' ', 1);
}
