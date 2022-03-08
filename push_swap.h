/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlalouli <hlalouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 11:22:52 by hlalouli          #+#    #+#             */
/*   Updated: 2022/03/06 14:45:40 by hlalouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include<stdio.h>
# include<unistd.h>
# include "checker_srcs/get_next_line.h"

typedef struct s_stack
{
	int		*stack;
	int		length;
	int		used_length;
}	t_stack;

typedef struct s_oper
{
	char			*data;
	struct s_oper	*next;
}	t_oper;

typedef struct s_var
{
	t_oper	*tmp;
	t_oper	*prev;
	t_oper	*fi;
	t_oper	*se;
}	t_var;

long	check_error(char *c);
int		check_duplicates(int	*l, int n);
void	error_msg(char *str);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s1);
int		ft_strlen(char *s);
char	**ft_split(char *s, char c);
char	**ft_ha(char *s, char **sp, char c);
char	*ft_substr(char *s, int start, int len);
char	**free_sp(char **sp);
int		ft_count(char *s, char c);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
int		*unit_stack(int n, char *s[]);
int		unit_length(int n, char *s[]);
char	*swap_stack(t_stack	*s, char c);
char	*push_stack_a(t_stack *a, t_stack *b);
char	*push_stack_b(t_stack *a, t_stack *b);
char	*rr_stack(t_stack *s, char c);
int		first(t_stack	*s);
char	*r_stack(t_stack	*s, char c);
void	sort_three(t_stack *a, t_oper **oper);
void	sort_two(t_stack *a, t_oper **oper);
int		is_sorted(t_stack *s);
int		min_stack(t_stack *s);
int		pos_stack(t_stack	*s, int p);
void	push_min1(t_stack *s, t_stack *b, t_oper **oper);
void	push_min2(t_stack *s, t_stack *b, t_oper **oper);
void	sort_4(t_stack *a, t_stack *b, t_oper **oper);
int		*arr_tab(t_stack *s, int len);
int		*sort_tab(t_stack *s, int len);
void	sort_five(t_stack *a, t_stack *b, t_oper **oper);
void	prt_stack(t_stack *a, t_stack *b);
void	print_stack(t_stack *a, t_stack *b);
void	pop_stack(t_stack *stack);
void	push_stack(t_stack *stack);
void	double_r_stack(t_stack *s, t_oper **oper);
void	double_rr_stack(t_stack *s, t_oper **oper);
int		mid_tab(t_stack *s, int len);
int		find_sort(t_stack *a, t_stack *b, char c, int mid);
int		sort_less_3(t_stack *a, int len, t_oper **oper);
int		find_sort_two(t_stack *a, t_stack *b, int len, t_oper **oper);
int		find_sort_b(t_stack *a, t_stack *b, int len, t_oper **oper);
void	inv_sort_three(t_stack *b, t_oper **oper);
void	inv_sort_two(t_stack *a);
int		sort_less_3_b(t_stack *b, int len, t_oper **oper);
int		is_inv_sorted(t_stack *s);
void	repet(t_stack *a, t_stack *b);
void	back_a(t_stack *a, int r, t_oper **oper);
void	back_b(t_stack *b, int r, t_oper **oper);
int		ft_sort_asc(t_stack *a, int len, t_oper **oper);
int		ft_sort_desc(t_stack *b, int len,	t_oper **oper);
void	check_a_len(t_stack *a, t_stack *b,	t_oper **oper);
void	optim_operations(t_oper **oper);
void	optim_sasa(t_oper **oper, int *flag, int *all);
void	optim_sbsb(t_oper **oper, int *flag, int *all);
void	optim_pbpa(t_oper **oper, int *flag, int *all);
void	optim_rrara(t_oper **oper, int *flag, int *all);
void	optim_rrbrb(t_oper **oper, int *flag, int *all);
void	facl1(t_oper *fi, t_oper *se, t_oper *prev, t_oper *tmp);
void	facl2(t_oper *prev, t_oper *tmp);
void	optim_rarb(t_oper **oper, int *flag, int *all);
void	optim_sasb(t_oper **oper, int *flag, int *all);
void	optim_rrarrb(t_oper **oper, int *flag, int *all);
int		ft_sequ(char const *s1, char const *s2);
void	remove_ele(t_oper *head);
void	double_remove(t_oper *second, t_oper *first);
void	remove_oper(t_oper **head);
void	add_oper(t_oper **head, char *data);
void	print_operations(t_oper *oper);
void	ft_strdel(char **as);
void	check_null_emptystr(char **split);
void	ft_putendl(char *s);
void	sort_three1(t_stack *a, t_oper **oper);
void	break_programm(t_stack *a, t_stack *b);
void	init_commands(char *comm, t_stack *a, t_stack *b);
void	read_commands(t_stack *a, t_stack *b);
void	sswap(t_stack *a, t_stack *b);
void	rrotate(t_stack *a, t_stack *b);
void	rrevrotate(t_stack *a, t_stack *b);
int		ft_strcmp(char *s1, char *s2);
void	free_memory(t_stack *a, t_stack *b);

#endif