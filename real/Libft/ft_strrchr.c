/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 14:32:04 by yfu               #+#    #+#             */
/*   Updated: 2020/12/16 15:06:33 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*add;

	add = (char*)s;
	add += ft_strlen(s);
	while (add >= (char*)s)
	{
		if (*add == (char)c)
			return (add);
		else
			add--;
	}
	return (NULL);
}
