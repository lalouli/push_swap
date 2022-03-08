/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlalouli <hlalouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 22:04:41 by hlalouli          #+#    #+#             */
/*   Updated: 2022/03/06 14:58:36 by hlalouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	break_programm(t_stack *a, t_stack *b)
{
	free(a);
	free(b);
	free(a->stack);
	free(b->stack);
	write(2, "Error\n", 6);
	exit(0);
}

void	init_commands(char *comm, t_stack *a, t_stack *b)
{
	if (!ft_strcmp(comm, "sa\n"))
		swap_stack(a, 'a');
	else if (!ft_strcmp(comm, "sb\n"))
		swap_stack(b, 'b');
	else if (!ft_strcmp(comm, "ss\n"))
		sswap(a, b);
	else if (!ft_strcmp(comm, "pa\n"))
		push_stack_a(a, b);
	else if (!ft_strcmp(comm, "pb\n"))
		push_stack_b(a, b);
	else if (!ft_strcmp(comm, "ra\n"))
		r_stack(a, 'a');
	else if (!ft_strcmp(comm, "rb\n"))
		r_stack(b, 'b');
	else if (!ft_strcmp(comm, "rr\n"))
		rrotate(a, b);
	else if (!ft_strcmp(comm, "rra\n"))
		rr_stack(a, 'a');
	else if (!ft_strcmp(comm, "rrb\n"))
		rr_stack(b, 'b');
	else if (!ft_strcmp(comm, "rrr\n"))
		rrevrotate(a, b);
	else
		break_programm(a, b);
}

void	read_commands(t_stack *a, t_stack *b)
{
	char	*line;

	line = get_next_line(0);
	while (line != NULL)
	{
		init_commands(line, a, b);
		line = get_next_line(0);
	}
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = malloc(sizeof(t_stack));
	b = malloc(sizeof(t_stack));
	if (!a || !b)
		return (0);
	a->stack = unit_stack(ac, av);
	a->length = unit_length(ac, av);
	a->used_length = a->length;
	b->stack = malloc(a->used_length * sizeof(int));
	b->length = 0;
	b->used_length = 0;
	if (!a->stack)
		return (free(a), free(b), 0);
	if (!b->stack)
		return (free(a), free(b), 0);
	read_commands(a, b);
	if (is_sorted(a) && b->used_length == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_memory(a, b);
	return (0);
}
