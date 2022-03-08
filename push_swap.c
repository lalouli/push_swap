/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlalouli <hlalouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 22:05:42 by hlalouli          #+#    #+#             */
/*   Updated: 2022/03/06 14:56:56 by hlalouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char	*av[])
{
	t_stack	*a;
	t_stack	*b;
	t_oper	*oper;

	check_null_emptystr(av);
	a = malloc(sizeof(t_stack));
	b = malloc(sizeof(t_stack));
	if (!a || !b)
		return (0);
	a->stack = unit_stack(argc, av);
	a->length = unit_length(argc, av);
	a->used_length = a->length;
	b->stack = ft_calloc(a->used_length, sizeof(int));
	b->length = 0;
	b->used_length = 0;
	if (!b->stack)
		return (free(a), free(b), 0);
	if (!a->stack)
		return (free(a), free(b), 0);
	check_a_len(a, b, &oper);
	optim_operations(&oper);
	print_operations(oper);
	remove_oper(&oper);
	free_memory(a, b);
	return (0);
}
