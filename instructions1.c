/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlalouli <hlalouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:37:13 by hlalouli          #+#    #+#             */
/*   Updated: 2022/03/05 12:40:48 by hlalouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_stack(t_stack *s)
{
	int	min;
	int	i;

	i = 0;
	min = s->stack[i];
	while (++i < s->length)
	{
		if (min > s->stack[i])
			min = s->stack[i];
	}
	return (min);
}

int	pos_stack(t_stack	*s, int p)
{
	int	i;

	i = 0;
	while (i < s->length)
	{
		if (p == s->stack[i])
			return (i);
		i++;
	}
	return (-1);
}

void	push_min1(t_stack *s, t_stack *b, t_oper **oper)
{
	int	i;

	i = pos_stack(s, min_stack(s));
	if (i == 0)
		add_oper(oper, push_stack_b(s, b));
	else if (i == 1)
	{	
		add_oper(oper, swap_stack(s, 'a'));
		add_oper(oper, push_stack_b(s, b));
	}
	else if (i == 2)
	{
		double_r_stack(s, oper);
		add_oper(oper, push_stack_b(s, b));
	}
	else if (i == 3)
	{
		double_rr_stack(s, oper);
		add_oper(oper, push_stack_b(s, b));
	}
	else if (i == 4)
	{
		add_oper(oper, rr_stack(s, 'a'));
		add_oper(oper, push_stack_b(s, b));
	}
}

void	push_min2(t_stack *s, t_stack *b, t_oper **oper)
{
	int	i;
	int	min;

	min = min_stack(s);
	i = pos_stack(s, min);
	if (i == 0)
		add_oper(oper, push_stack_b(s, b));
	else if (i == 1)
	{
		add_oper(oper, swap_stack(s, 'a'));
		add_oper(oper, push_stack_b(s, b));
	}
	else if (i == 2)
	{
		double_rr_stack(s, oper);
		add_oper(oper, push_stack_b(s, b));
	}
	else if (i == 3)
	{
		add_oper(oper, rr_stack(s, 'a'));
		add_oper(oper, push_stack_b(s, b));
	}
}

int	is_sorted(t_stack *s)
{
	int	i;

	i = 0;
	while (i < s->used_length - 1)
	{
		if (s->stack[i] > s->stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}
