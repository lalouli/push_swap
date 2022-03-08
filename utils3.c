/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlalouli <hlalouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:08:04 by hlalouli          #+#    #+#             */
/*   Updated: 2022/03/05 12:41:53 by hlalouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_stack(t_stack *stack)
{
	int	used_size;

	used_size = stack->used_length;
	while (used_size > 0)
	{
		stack->stack[used_size] = stack->stack[used_size - 1];
		used_size--;
	}
}

void	pop_stack(t_stack *stack)
{
	int	i;
	int	used_size;

	i = 0;
	used_size = stack->used_length - 1;
	while (i < used_size)
	{
		stack->stack[i] = stack->stack[i + 1];
		i++;
	}
}

void	double_r_stack(t_stack *s, t_oper **oper)
{
	add_oper(oper, r_stack(s, 'a'));
	add_oper(oper, r_stack(s, 'a'));
}

void	double_rr_stack(t_stack *s, t_oper **oper)
{
	add_oper(oper, rr_stack(s, 'a'));
	add_oper(oper, rr_stack(s, 'a'));
}

void	ft_putendl(char *s)
{
	if (!s)
		return ;
	ft_putstr_fd(s, 1);
	ft_putchar_fd('\n', 1);
}
