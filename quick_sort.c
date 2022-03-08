/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlalouli <hlalouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 15:04:23 by hlalouli          #+#    #+#             */
/*   Updated: 2022/03/05 13:07:10 by hlalouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	back_a(t_stack *a, int r, t_oper **oper)
{
	if (r > a->used_length / 2)
		while (a->used_length - r++ > 0)
			add_oper(oper, r_stack(a, 'a'));
	else
		while (r--)
			add_oper(oper, rr_stack(a, 'a'));
}

void	back_b(t_stack *b, int r, t_oper **oper)
{
	if (r > b->used_length / 2)
		while (b->used_length - r++ > 0)
			add_oper(oper, r_stack(b, 'b'));
	else
		while (r--)
			add_oper(oper, rr_stack(b, 'b'));
}

int	*arr_tab(t_stack *s, int len)
{
	int	i;
	int	*arr;

	i = 0;
	if (s->stack == NULL)
		return (0);
	arr = ft_calloc(len, sizeof(int));
	if (!arr)
		return (0);
	while (i < len)
	{
		arr[i] = s->stack[i];
		i++;
	}
	return (arr);
}

int	*sort_tab(t_stack *s, int len)
{
	int	i;
	int	j;
	int	tmp;
	int	*arr;

	arr = arr_tab(s, len);
	i = 0;
	while (i < len - 1)
	{
		j = 0;
		while (j < len - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	return (arr);
}

int	mid_tab(t_stack *s, int len)
{
	int	mid;
	int	*arr;

	arr = sort_tab(s, len);
	mid = arr[len / 2];
	return (free(arr), arr = NULL, mid);
}
