/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_3_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 09:53:31 by yfu               #+#    #+#             */
/*   Updated: 2021/01/26 09:53:32 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_3_1_0(t_form form, int *cnt)
{
	if (form.flag[1] || form.flag[2])
	{
		(*cnt)++;
		form.width--;
	}
	(*cnt) += ft_max(0, form.width);
	if (form.flag[0] == 0)
		while (form.width-- > 0)
			ft_putchar_fd(' ', 1);
	if (form.flag[1] || form.flag[2])
		ft_putchar_fd(form.flag[1] ? '+' : ' ', 1);
	while (form.width-- > 0)
		ft_putchar_fd(' ', 1);
}

static void	ft_3_1_1_0(t_form form, int *cnt)
{
	(*cnt) += ft_max(form.width, ft_max(form.precision + 1, 20));
	form.precision = ft_max(form.precision - 19, 0);
	form.width = ft_max(form.width - form.precision - 20, 0);
	if (form.flag[0] == 0 && form.flag[4] == 0)
		while (form.width-- > 0)
			ft_putchar_fd(' ', 1);
	ft_putchar_fd('-', 1);
	while (form.precision-- > 0)
		ft_putchar_fd('0', 1);
	if (form.flag[4])
		while (form.width-- > 0)
			ft_putchar_fd('0', 1);
	ft_putstr_fd("9223372036854775808", 1);
	while (form.width-- > 0)
		ft_putchar_fd(' ', 1);
}

static void	ft_3_1_1_1(t_form form, int *cnt, long long *ct)
{
	ct[4] = (ct[0] < 0LL || form.flag[1] || form.flag[2]) ? 1LL : 0LL;
	(*cnt) += ft_max(form.width, ft_max(form.precision, (int)ct[2])
													+ (int)ct[4]);
	form.precision = ft_max(form.precision - (int)ct[2], 0);
	form.width = ft_max(form.width - form.precision - (int)(ct[2] + ct[4]), 0);
	if (form.flag[0] == 0 && form.flag[4] == 0)
		while (form.width-- > 0)
			ft_putchar_fd(' ', 1);
	if (ct[0] < 0LL)
		ft_putchar_fd('-', 1);
	else if (form.flag[1] || form.flag[2])
		ft_putchar_fd(form.flag[1] ? '+' : ' ', 1);
	while (form.precision-- > 0)
		ft_putchar_fd('0', 1);
	if (form.flag[4])
		while (form.width-- > 0)
			ft_putchar_fd('0', 1);
	ft_putll(ct[0]);
	while (form.width-- > 0)
		ft_putchar_fd(' ', 1);
}

void		ft_3_1_1(t_form form, int *cnt, long long *ct)
{
	long long	llmin;

	llmin = -9223372036854775807LL;
	llmin--;
	ct[2] = 1LL;
	while (ct[1] > 9LL || ct[1] < -9LL)
	{
		ct[2]++;
		ct[1] /= 10LL;
	}
	if (form.precision != -1 || form.flag[0])
		form.flag[4] = 0;
	if (ct[0] == llmin)
		ft_3_1_1_0(form, cnt);
	else
		ft_3_1_1_1(form, cnt, ct);
}

void		ft_3_1(t_form form, va_list *arg, int *cnt)
{
	long long int	ct[5];

	ct[0] = va_arg(*arg, long long int);
	ct[1] = ct[0];
	if (ct[0] == 0LL && form.precision == 0)
		ft_3_1_0(form, cnt);
	else
		ft_3_1_1(form, cnt, (long long*)ct);
}
