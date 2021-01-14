/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 12:36:12 by yfu               #+#    #+#             */
/*   Updated: 2020/12/22 12:36:38 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t j;

	if (n == 0)
		return (ft_strlen(s2));
	i = 0;
	while (s1[i] != '\0' && i < n)
		i++;
	j = i;
	while (i < n - 1 && s2[i - j] != '\0')
	{
		s1[i] = s2[i - j];
		i++;
	}
	if (j < n)
		s1[i] = '\0';
	return (j + ft_strlen(s2));
}
