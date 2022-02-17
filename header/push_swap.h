/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: embedois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:07:34 by embedois          #+#    #+#             */
/*   Updated: 2022/02/17 17:05:48 by embedois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stacks
{
	int	*a;
	int	*b;
	int	len_a;
	int	len_b;
}	t_stacks;

int	ft_atoi(const char *str);
long int	ft_atoli(const char *str);

int	n_words(char const *s, char c);
char	**ft_split(char const *s, char c);
char	**ft_free_split(char **array, int j);

char	*ft_substr(char const *s, unsigned int start, size_t len);

int	parsing(int ac, char **av);
int	is_int(char *str);
int	is_list(char *str);
int	is_sorted(t_stacks s);
int	parse(int ac, char **av);

t_stacks	ft_putmove(char *str, t_stacks s, int n);
int	ft_putstr(char *str);
int	print_error(void);

int	*ft_cpy(int *tmp, int *a, int len);
int	is_lowest(int *array, int len);

t_stacks	solver(t_stacks s);
t_stacks	solve2(t_stacks s);
t_stacks	solve3(t_stacks s);
t_stacks	solve4(t_stacks s);
t_stacks	solve5(t_stacks s);
t_stacks	bigsolver(t_stacks s);
t_stacks	prepLIS(t_stacks s);
t_stacks	LIS(int *stack, int len);
t_stacks	best_move(t_stacks s);

t_stacks	ft_fill(t_stacks s, char **av, int ac);
t_stacks	ft_init2(int ac, char **av);
t_stacks	ft_init1(char **av);

t_stacks	ft_swap(t_stacks s, char c);
t_stacks	ft_push(t_stacks s, char c);
t_stacks	ft_rotate(t_stacks s, char c);
t_stacks	ft_reverse_rotate(t_stacks s, char c);
#endif
