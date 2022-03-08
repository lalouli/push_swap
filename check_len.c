/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlalouli <hlalouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 17:09:35 by hlalouli          #+#    #+#             */
/*   Updated: 2022/03/06 14:55:46 by hlalouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_a_len(t_stack *a, t_stack *b, t_oper **oper)
{
	if (a->length == 2)
		sort_two(a, oper);
	else if (a->length == 3)
		sort_three(a, oper);
	else if (a->length == 4)
		sort_4(a, b, oper);
	else if (a->length == 5)
		sort_five(a, b, oper);
	else
		find_sort_two(a, b, a->used_length, oper);
}

void	check_null_emptystr(char **split)
{
	int	i;
	int	j;
	int	valid;

	i = 0;
	while (split[++i])
	{
		j = -1;
		valid = 0;
		while (split[i][++j] && !valid)
			if (split[i][j] != ' ')
				valid = 1;
		if (!valid)
			return (ft_putstr_fd("Error", 2), exit(1));
	}
	if (!valid)
		return (ft_putstr_fd("Error", 2), exit(1));
}

void	free_memory(t_stack *a, t_stack *b)
{
	free(b->stack);
	free(a->stack);
	free(a);
	free(b);
}
