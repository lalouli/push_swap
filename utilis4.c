/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlalouli <hlalouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 19:19:03 by hlalouli          #+#    #+#             */
/*   Updated: 2022/03/05 22:31:45 by hlalouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sswap(t_stack *a, t_stack *b)
{
	swap_stack(a, 'a');
	swap_stack(b, 'b');
}

void	rrotate(t_stack *a, t_stack *b)
{
	r_stack(a, 'a');
	r_stack(b, 'b');
}

void	rrevrotate(t_stack *a, t_stack *b)
{
	rr_stack(a, 'a');
	rr_stack(b, 'b');
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s2)
		return (1);
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}
