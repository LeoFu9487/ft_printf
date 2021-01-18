/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 14:47:31 by yfu               #+#    #+#             */
/*   Updated: 2020/12/16 16:02:20 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	ct;

	ct = 0;
	while (s[ct])
	{
		if (s[ct] == (char)c)
			return ((char*)s + ct);
		ct++;
	}
	if (s[ct] == (char)c)
		return ((char*)s + ct);
	return (0);
}
