/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 11:43:16 by yfu               #+#    #+#             */
/*   Updated: 2020/12/22 11:43:20 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*dd;

	temp = *lst;
	*lst = NULL;
	while (temp)
	{
		if (del)
			del(temp->content);
		dd = temp;
		temp = temp->next;
		free(dd);
	}
}
