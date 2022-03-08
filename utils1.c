/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlalouli <hlalouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 08:42:41 by hlalouli          #+#    #+#             */
/*   Updated: 2022/03/05 14:33:59 by hlalouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (*s)
	{
		if (*s != c && count == 0)
		{
			count = 1;
			i++;
		}
		else if (*s == c)
			count = 0;
		s++;
	}
	return (i);
}

char	**free_sp(char **sp)
{
	int	i;

	i = 0;
	while (sp[i])
		free(sp[i++]);
	free(sp);
	return (NULL);
}

char	*ft_substr(char *s, int start, int len)
{
	int		i;
	char	*pt;

	i = 0;
	if (!s)
		return (NULL);
	if (start < ft_strlen(s))
	{
		if (ft_strlen(s) < len)
			len = ft_strlen(s);
		pt = (char *)malloc(len + 1);
		if (!pt)
			return (NULL);
		while (i < len)
			*(pt + i++) = *(s + start++);
		*(pt + i) = '\0';
		return (pt);
	}
	pt = malloc(1);
	if (!pt)
		return (pt);
	*(pt + i) = '\0';
	return (pt);
}

char	**ft_ha(char *s, char **sp, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		j = 0;
		while (s[i + j] && s[i + j] != c)
			j++;
		if (j != 0)
			sp[k++] = ft_substr(s, i, j);
		if (j != 0 && !sp[k - 1])
			return (free_sp(sp), NULL);
		i += j;
	}
	sp[k] = NULL;
	return (sp);
}

char	**ft_split(char *s, char c)
{
	char	**sp;

	if (!s)
		return (0);
	sp = (char **)ft_calloc(ft_count(s, c) + 1, sizeof(char *));
	if (!sp)
		return (NULL);
	sp = ft_ha(s, sp, c);
	return (sp);
}
