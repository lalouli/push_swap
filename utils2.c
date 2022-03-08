/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlalouli <hlalouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 08:51:05 by hlalouli          #+#    #+#             */
/*   Updated: 2022/02/28 16:24:38 by hlalouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*res;

	res = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		res[i] = (unsigned char) c;
		i++;
	}	
	return (res);
}

void	ft_bzero(void *s, size_t n)
{
	if (n > 0)
		ft_memset(s, '\0', n);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*res;

	res = malloc(count * size);
	if (!res)
		return (NULL);
	ft_bzero(res, size * count);
	return (res);
}

void	error_msg(char *str)
{
	ft_putstr_fd(str, 2);
	exit(1);
}
