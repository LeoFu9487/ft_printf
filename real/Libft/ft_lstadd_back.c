/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 11:43:07 by yfu               #+#    #+#             */
/*   Updated: 2020/12/22 11:43:11 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	temp = ft_lstlast(*lst);
	if (!temp)
	{
		*lst = new;
		return ;
	}
	if (!new)
		return ;
	temp->next = new;
}
