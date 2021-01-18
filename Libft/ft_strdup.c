/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 12:37:51 by yfu               #+#    #+#             */
/*   Updated: 2020/12/22 12:37:53 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strdup(const char *source)
{
	char	*ans;
	int		len;
	int		i;

	len = ft_strlen(source);
	if (!(ans = (char*)malloc((len + 1) * sizeof(char))))
		return (NULL);
	i = -1;
	while (++i < len)
		ans[i] = source[i];
	ans[i] = '\0';
	return (ans);
}
