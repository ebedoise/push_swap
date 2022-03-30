/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: embedois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:07:34 by embedois          #+#    #+#             */
/*   Updated: 2022/03/30 14:13:07 by embedois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "get_next_line.h"

typedef struct s_stacks
{
	int		*a;
	int		*b;
	int		len_a;
	int		len_b;
}	t_stacks;

size_t		ft_strlen(char const *str);

char		**ft_split(char const *s, char c);
char		**ft_free_split(char **array, int j);
char		*ft_substr(char const *s, unsigned int start, size_t len);

long int	ft_atoli(const char *str);

int			parsing(int ac, char **av);
int			is_int(char *str);
int			is_list(char *str);
int			is_in_lis(int n, t_stacks lis_var);
int			is_sorted(t_stacks s);
int			parse(int ac, char **av);
int			biggest(t_stacks s);
int			pos_in_a(t_stacks s, int n);
int			ft_abs_moves(int a, int b);
int			final_order(t_stacks s);
int			ft_putstr(char *str);
int			print_error(void);
int			*ft_cpy(int *tmp, int *a, int len);
int			is_lowest(int *array, int len);
int			n_words(char const *s, char c);
int			ft_atoi(const char *str);

int			check_stdin(t_stacks s);
int			ft_strcmp(char *s1, char *s2);
int			ft_free_split2(char **array, int j);

t_stacks	solver(t_stacks s);
t_stacks	solve2(t_stacks s);
t_stacks	solve3(t_stacks s);
t_stacks	solve4(t_stacks s);
t_stacks	solve5(t_stacks s);
t_stacks	bigsolver(t_stacks s);
t_stacks	prep_lis(t_stacks s);
t_stacks	lis(int *stack, int len);
t_stacks	best_move(t_stacks s);
t_stacks	ft_fill(t_stacks s, char **av, int ac);
t_stacks	ft_init2(int ac, char **av);
t_stacks	ft_init1(char **av);
t_stacks	ft_swap(t_stacks s, char c);
t_stacks	ft_push(t_stacks s, char c);
t_stacks	ft_rotate(t_stacks s, char c);
t_stacks	ft_reverse_rotate(t_stacks s, char c);
t_stacks	ft_putmove(char *str, t_stacks s, int n);
t_stacks	smallest(t_stacks s);
#endif
