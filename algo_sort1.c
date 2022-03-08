/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sort1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlalouli <hlalouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 16:52:09 by hlalouli          #+#    #+#             */
/*   Updated: 2022/03/05 13:04:11 by hlalouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	need_p(t_stack *head, int id, int len, int pivot)
{
	t_stack	*ptr;
	int		i;

	ptr = head;
	i = 0;
	while (len--)
	{
		if (id == 1 && ptr->stack[i] < pivot)
			return (1);
		else if (id == 2 && ptr->stack[i] > pivot)
			return (1);
		i++;
	}
	return (0);
}

int	ft_sort_desc(t_stack *b, int len, t_oper **oper)
{
	while (len-- > 1)
	{
		if (b->stack[0] < b->stack[1])
		{
			add_oper(oper, swap_stack(b, 'b'));
			add_oper(oper, r_stack(b, 'b'));
		}
		else
			add_oper(oper, r_stack(b, 'b'));
	}
	while (++len < 3)
	{
		add_oper(oper, rr_stack(b, 'b'));
		if (b->stack[0] < b->stack[0])
			add_oper(oper, swap_stack(b, 'b'));
	}
	if (b->stack[0] < b->stack[1])
		add_oper(oper, swap_stack(b, 'b'));
	return (0);
}

int	find_sort_two(t_stack *a, t_stack *b, int len, t_oper **oper)
{
	int	i;
	int	mid;
	int	ra;
	int	pb;

	ra = 0;
	pb = 0;
	i = 0;
	if (len <= 3)
		return (sort_less_3(a, len, oper), 0);
	mid = mid_tab(a, len);
	while (need_p(a, 1, len - i, mid) && i++ < len)
	{
		if (a->stack[0] < mid && ++pb)
			add_oper(oper, push_stack_b(a, b));
		else if (a->stack[0] >= mid && ++ra)
			add_oper(oper, r_stack(a, 'a'));
	}
	back_a(a, ra, oper);
	find_sort_two(a, b, len - pb, oper);
	find_sort_b(a, b, pb, oper);
	while (pb--)
		add_oper(oper, push_stack_a(a, b));
	return (0);
}

int	find_sort_b(t_stack *a, t_stack *b, int len, t_oper **oper)
{
	int	i;
	int	mid;
	int	pa;
	int	rb;

	rb = 0;
	pa = 0;
	i = 0;
	if (len <= 3)
		return (sort_less_3_b(b, len, oper), 0);
	mid = mid_tab(b, len);
	while (need_p(b, 2, len - i, mid) && i++ < len)
	{
		if (b->stack[0] > mid && ++pa)
			add_oper(oper, push_stack_a(a, b));
		else if (b->stack[0] <= mid && ++rb)
			add_oper(oper, r_stack(b, 'b'));
	}
	find_sort_two(a, b, pa, oper);
	back_b(b, rb, oper);
	find_sort_b(a, b, len - pa, oper);
	while (pa--)
		add_oper(oper, push_stack_b(a, b));
	return (0);
}

void	sort_three(t_stack *a, t_oper **oper)
{
	if (is_sorted(a) == 1)
		return ;
	if (a->stack[0] > a->stack[1] && a->stack[0] < a->stack[2])
		add_oper(oper, swap_stack(a, 'a'));
	else if (a->stack[0] > a->stack[1] && a->stack[1] > a->stack[2])
	{
		add_oper(oper, swap_stack(a, 'a'));
		add_oper(oper, rr_stack(a, 'a'));
	}
	else if (a->stack[0] > a->stack[1] && a->stack[1] < a->stack[2])
		add_oper(oper, r_stack(a, 'a'));
	else if (a->stack[0] < a->stack[1] && a->stack[0] < a->stack[2])
	{
		add_oper(oper, swap_stack(a, 'a'));
		add_oper(oper, r_stack(a, 'a'));
	}
	else if (a->stack[0] < a->stack[1] && a->stack[1] > a->stack[2] \
		&& a->stack[0] > a->stack[2])
		add_oper(oper, rr_stack(a, 'a'));
}
