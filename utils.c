/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlalouli <hlalouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 12:40:10 by hlalouli          #+#    #+#             */
/*   Updated: 2022/02/12 11:01:33 by hlalouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
		ft_putchar_fd(s[i++], fd);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	int		i;
	int		j;
	int		s1_len;
	int		s2_len;

	if (!s1)
		s1 = ft_strdup("");
	if (!s2)
		s2 = ft_strdup("");
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	s3 = malloc(s1_len + s2_len + 1 * sizeof(char));
	if (!s3)
		return (NULL);
	i = -1;
	while (++i < s1_len)
		s3[i] = s1[i];
	j = 0;
	while (i < s1_len + s2_len)
		s3[i++] = s2[j++];
	s3[i] = '\0';
	free(s1);
	return (s3);
}

char	*ft_strdup(char *s1)
{
	int		l;
	int		i;
	char	*s2;

	if (!s1)
		return (NULL);
	l = ft_strlen(s1);
	s2 = (char *) malloc(l + 1);
	if (!s2)
		return (s2);
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != 0)
		i++;
	return (i);
}
