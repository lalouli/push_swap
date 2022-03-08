/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chek_output.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlalouli <hlalouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 11:22:05 by hlalouli          #+#    #+#             */
/*   Updated: 2022/03/05 23:29:47 by hlalouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*unit_stack(int n, char *s[])
{
	int		i;
	t_stack	a;
	char	**split;
	char	*join;

	join = ft_strdup("");
	i = 1;
	while (i < n)
	{
		join = ft_strjoin(join, s[i++]);
		join = ft_strjoin(join, " ");
	}
	split = ft_split(join, ' ');
	a.length = ft_count(join, ' ');
	if (ft_count(join, ' ') == 1 && check_error(split[0]))
		return (0);
	i = -1;
	a.stack = (int *)malloc(sizeof(int) * (ft_count(join, ' ')));
	while (a.stack && ++i < ft_count(join, ' '))
		a.stack[i] = check_error(split[i]);
	if (a.stack && check_duplicates(a.stack, a.length) == 1)
		error_msg("Error\n");
	return (free(join), free_sp(split), a.stack);
}

int	unit_length(int n, char *s[])
{
	int		i;
	t_stack	a;
	char	*join;

	join = ft_strdup("");
	i = 1;
	while (i < n)
	{
		join = ft_strjoin(join, s[i++]);
		join = ft_strjoin(join, " ");
	}
	a.length = ft_count(join, ' ');
	return (free(join), a.length);
}

long	check_error(char *c)
{
	long	i;
	int		k;

	i = 0;
	k = 1;
	if (*c == '-')
	{
		k = -1;
		c++;
	}
	else if (*c == '+')
		c++;
	if (!*c)
		error_msg("Error\n");
	while (*c && *c >= '0' && *c <= '9')
	{
		i *= 10;
		i += *c - '0';
		if (i * k > 2147483647 || i * k < -2147483648)
			error_msg("Error\n");
		c++;
	}
	if ((*c < '0' || *c > '9') && *c)
		error_msg("Error\n");
	return (i * k);
}

int	check_duplicates(int	*l, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		j = i + 1;
		while (j < n)
		{
			if (l[i] == l[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
