/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlalouli <hlalouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:56:30 by hlalouli          #+#    #+#             */
/*   Updated: 2022/03/05 21:57:21 by hlalouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_less_3(t_stack *a, int len, t_oper **oper)
{
	int		x;
	int		y;
	int		z;

	x = a->stack[0];
	if (len >= 2)
		y = a->stack[1];
	else
		y = 0;
	if (len == 3)
		z = a->stack[2];
	else
		z = 0;
	if (len == 1)
		return (0);
	else if (len == 2 && x > y)
		add_oper(oper, swap_stack(a, 'a'));
	else if (a->used_length == 3 && len == 3)
		sort_three(a, oper);
	else if (len == 3)
		ft_sort_asc(a, len, oper);
	return (0);
}

void	sort_two(t_stack *a, t_oper **oper)
{
	if (!is_sorted(a))
		add_oper(oper, swap_stack(a, 'a'));
	else
		return ;
}

void	sort_five(t_stack *a, t_stack *b, t_oper **oper)
{
	if (is_sorted(a) == 1)
		return ;
	push_min1(a, b, oper);
	push_min2(a, b, oper);
	sort_three(a, oper);
	add_oper(oper, push_stack_a(a, b));
	add_oper(oper, push_stack_a(a, b));
}

void	sort_4(t_stack *a, t_stack *b, t_oper **oper)
{
	if (is_sorted(a) == 1)
		return ;
	push_min2(a, b, oper);
	sort_three(a, oper);
	add_oper(oper, push_stack_a(a, b));
}
