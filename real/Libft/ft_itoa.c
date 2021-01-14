/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 11:42:56 by yfu               #+#    #+#             */
/*   Updated: 2020/12/22 11:43:04 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_cnt(int n)
{
	int	ans;

	ans = n < 0 ? 1 : 0;
	while (n != 0)
	{
		ans++;
		n /= 10;
	}
	return (ans);
}

char			*ft_itoa(int n)
{
	char	*ans;
	int		ct;

	ans = NULL;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	ct = ft_cnt(n);
	if (!(ans = (char*)malloc((ct + 1) * sizeof(char))))
		return (NULL);
	if (n < 0)
		ans[0] = '-';
	ans[ct] = '\0';
	n = n < 0 ? -1 * n : n;
	while (n > 0)
	{
		ans[--ct] = n % 10 + '0';
		n /= 10;
	}
	return (ans);
}
