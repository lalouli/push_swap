/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimiser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlalouli <hlalouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:34:47 by hlalouli          #+#    #+#             */
/*   Updated: 2022/03/04 15:50:33 by hlalouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	optim_operations(t_oper **oper)
{
	int		flag;
	int		all;

	all = 1;
	flag = 0;
	while (all && (*oper))
	{
		all = 0;
		optim_sasa(oper, &flag, &all);
		optim_sbsb(oper, &flag, &all);
		optim_pbpa(oper, &flag, &all);
		optim_rrara(oper, &flag, &all);
		optim_rrbrb(oper, &flag, &all);
		optim_rarb(oper, &flag, &all);
		optim_sasb(oper, &flag, &all);
		optim_rrarrb(oper, &flag, &all);
	}
}

int	ft_sequ(char const *s1, char const *s2)
{
	if (!s1 || !s2)
		return (0);
	while ((*s1 - *s2) == 0 && *s1 && *s2)
	{
		s1++;
		s2++;
	}
	if ((*s1 - *s2) != 0)
		return (0);
	return (1);
}

void	ft_strdel(char **as)
{
	if (as != NULL)
	{
		free(*as);
		*as = NULL;
	}
}
