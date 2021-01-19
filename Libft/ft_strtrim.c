/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 12:38:07 by yfu               #+#    #+#             */
/*   Updated: 2020/12/22 12:38:19 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strtrim(char const *s1, char const *set)
{
	char	*ans;
	int		ct[2];
	int		ascii[1000];

	ct[0] = -1;
	while (++ct[0] < 1000)
		ascii[ct[0]] = 0;
	ct[0] = -1;
	while (set[++ct[0]])
		ascii[(int)set[ct[0]]]++;
	ct[0] = -1;
	while (s1[++ct[0]])
		if (ascii[(int)s1[ct[0]]] == 0)
			break ;
	ct[1] = ft_strlen(s1);
	while (--ct[1] >= 0)
		if (ascii[(int)s1[ct[1]]] == 0)
			break ;
	if (!(ans = ft_substr(s1, ct[0], ct[1] - ct[0] + 1)))
		return (NULL);
	return (ans);
}
