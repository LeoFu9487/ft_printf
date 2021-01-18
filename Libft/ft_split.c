/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 12:38:31 by yfu               #+#    #+#             */
/*   Updated: 2020/12/22 12:38:52 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_cnt(char const *s, char c)
{
	int		ct[2];

	if (!s)
		return (-1);
	ct[0] = 0;
	ct[1] = 0;
	while (s[ct[0]])
	{
		while (s[ct[0]] && s[ct[0]] == c)
			ct[0]++;
		if (!s[ct[0]])
			break ;
		while (s[ct[0]] && s[ct[0]] != c)
			ct[0]++;
		ct[1]++;
	}
	return (ct[1]);
}

static int		ft_sub(char **ans, const char *s, int *ct)
{
	if (!(ans[ct[1]++] = ft_substr(s, ct[0] - ct[2], ct[2])))
		return (0);
	return (1);
}

static char		**ft_free(char **ans)
{
	int	ct;

	ct = -1;
	while (ans[++ct])
		free(ans[ct]);
	free(ans);
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	char	**ans;
	int		sz;
	int		ct[3];

	sz = ft_cnt(s, c);
	if (!s || !(ans = (char**)malloc((sz + 1) * sizeof(char*))))
		return (NULL);
	ct[0] = 0;
	ct[1] = 0;
	while (s[ct[0]])
	{
		ct[2] = 0;
		while (s[ct[0]] && s[ct[0]] == c)
			ct[0]++;
		while (s[ct[0]] && s[ct[0]] != c)
		{
			ct[0]++;
			ct[2]++;
		}
		if (ct[2] > 0)
			if (!ft_sub(ans, s, (int*)ct))
				return (ft_free(ans));
	}
	ans[ct[1]] = NULL;
	return (ans);
}
