/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlalouli <hlalouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 15:48:36 by hlalouli          #+#    #+#             */
/*   Updated: 2022/03/05 12:41:39 by hlalouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	inv_sort_three(t_stack *b, t_oper **oper)
{
	if (b->stack[0] < b->stack[1] && b->stack[0] > b->stack[2])
		add_oper(oper, swap_stack(b, 'b'));
	else if (b->stack[0] < b->stack[1] && b->stack[1] < b->stack[2])
	{
		add_oper(oper, swap_stack(b, 'b'));
		add_oper(oper, rr_stack(b, 'b'));
	}
	else if (b->stack[0] < b->stack[1] && b->stack[1] > b->stack[2])
		add_oper(oper, r_stack(b, 'b'));
	else if (b->stack[0] > b->stack[1] && b->stack[0] > b->stack[2] \
		&& b->stack[1] < b->stack[2])
	{
		add_oper(oper, swap_stack(b, 'b'));
		add_oper(oper, r_stack(b, 'b'));
	}
	else if (b->stack[0] > b->stack[1] && b->stack[1] < b->stack[2] \
		&& b->stack[0] < b->stack[2])
		add_oper(oper, rr_stack(b, 'b'));
}

void	inv_sort_two(t_stack *a)
{
	if (!is_inv_sorted(a))
		swap_stack(a, 'b');
	else
		return ;
}

int	sort_less_3_b(t_stack *b, int len, t_oper **oper)
{
	int		x;
	int		y;
	int		z;

	x = b->stack[0];
	if (len >= 2)
		y = b->stack[1];
	else
		y = 0;
	if (len == 3)
		z = b->stack[2];
	else
		z = 0;
	if (len == 1)
		return (0);
	else if (len == 2 && x < y)
		add_oper(oper, swap_stack(b, 'b'));
	else if (b->used_length == 3 && len == 3)
		inv_sort_three(b, oper);
	else if (len == 3)
		ft_sort_desc(b, len, oper);
	return (0);
}

int	is_inv_sorted(t_stack *s)
{
	int	i;

	i = 0;
	while (i < s->used_length - 1)
	{
		if (s->stack[i] < s->stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	ft_sort_asc(t_stack *a, int len, t_oper **oper)
{
	while (len-- > 1)
	{
		if (a->stack[0] > a->stack[1])
		{
			add_oper(oper, swap_stack(a, 'a'));
			add_oper(oper, r_stack(a, 'a'));
		}
		else
			add_oper(oper, r_stack(a, 'a'));
	}
	while (++len < 3)
	{
		add_oper(oper, rr_stack(a, 'a'));
		if (a->stack[0] > a->stack[0])
			add_oper(oper, swap_stack(a, 'a'));
	}
	if (a->stack[0] > a->stack[1])
		add_oper(oper, swap_stack(a, 'a'));
	return (0);
}
