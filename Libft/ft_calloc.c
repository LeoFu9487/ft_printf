/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 11:42:36 by yfu               #+#    #+#             */
/*   Updated: 2020/12/22 11:42:42 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_calloc(size_t elementcount, size_t elementsize)
{
	void	*ans;

	if (!(ans = malloc(elementcount * elementsize)))
		return (NULL);
	ft_memset(ans, 0, elementcount * elementsize);
	return (ans);
}
