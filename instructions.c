/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlalouli <hlalouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 19:39:17 by hlalouli          #+#    #+#             */
/*   Updated: 2022/03/05 12:50:48 by hlalouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*swap_stack(t_stack	*s, char c)
{
	int	*a;
	int	n;
	int	t;

	a = s->stack;
	n = s->length;
	t = a[0];
	a[0] = a[1];
	a[1] = t;
	if (c == 'a')
		return ("sa");
	if (c == 'b')
		return ("sb");
	return (NULL);
}

char	*push_stack_b(t_stack *a, t_stack *b)
{
	int	used_size_b;
	int	used_size_a;

	used_size_b = b->used_length;
	used_size_a = a->used_length;
	if (used_size_a == 0)
		return (NULL);
	if (used_size_b == 0)
		b->stack[0] = a->stack[0];
	else
	{
		push_stack(b);
		b->stack[0] = a->stack[0];
	}
	pop_stack(a);
	b->used_length++;
	a->used_length--;
	return ("pb");
}

char	*push_stack_a(t_stack *a, t_stack *b)
{
	int	used_size_b;
	int	used_size_a;
	int	i;

	i = 0;
	used_size_b = b->used_length;
	used_size_a = a->used_length;
	if (used_size_a == 0)
		return (NULL);
	push_stack(a);
	a->stack[0] = b->stack[0];
	pop_stack(b);
	b->used_length--;
	a->used_length++;
	return ("pa");
}

char	*rr_stack(t_stack *s, char c)
{
	int	*a;
	int	n;
	int	last;
	int	i;

	a = s->stack;
	n = s->used_length;
	last = a[n - 1];
	i = n - 1;
	while (i > 0)
	{
		a[i] = a[i - 1];
		i--;
	}
	a[0] = last;
	if (c == 'a')
		return ("rra");
	if (c == 'b')
		return ("rrb");
	return (NULL);
}

char	*r_stack(t_stack	*s, char c)
{
	int	*a;
	int	n;
	int	first;
	int	i;

	a = s->stack;
	n = s->used_length;
	first = a[0];
	i = 0;
	while (i < n - 1)
	{
		a[i] = a [i + 1];
		i++;
	}
	a [n - 1] = first;
	if (c == 'a')
		return ("ra");
	if (c == 'b')
		return ("rb");
	return (NULL);
}
