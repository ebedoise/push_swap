/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: embedois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:02:23 by embedois          #+#    #+#             */
/*   Updated: 2022/02/21 15:55:48 by embedois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	is_sorted(t_stacks s)
{
	int	i;

	i = 0;
	while (i < s.len_a - 1)
	{
		if (s.a[i] < s.a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

t_stacks	ft_fill(t_stacks s, char **av, int ac)
{
	int	i;
	int	j;

	i = ac - 1;
	j = 0;
	while (i >= 0)
	{
		s.a[j] = ft_atoi(av[i]);
		i--;
		j++;
	}
	return (s);
}

t_stacks	ft_init2(int ac, char **av)
{
	t_stacks	s;

	s.a = malloc(sizeof(int) * (ac - 1));
	if (!s.a)
		return (s);
	s.len_a = ac - 1;
	s.b = malloc(sizeof(int) * (ac - 1));
	if (!s.b)
		return (s);
	s.len_b = 0;
	s = ft_fill(s, av + 1, ac - 1);
	return (s);
}

t_stacks	ft_init1(char **av)
{
	char		**array;
	t_stacks	s;

	s.a = malloc(sizeof(int) * n_words(av[1], ' '));
	if (!s.a)
		return (s);
	s.len_a = n_words(av[1], ' ');
	s.b = malloc(sizeof(int) * n_words(av[1], ' '));
	if (!s.b)
		return (s);
	s.len_b = 0;
	array = ft_split(av[1], ' ');
	if (!array)
		return (s);
	s = ft_fill(s, array, s.len_a);
	ft_free_split(array, s.len_a);
	return (s);
}

int	main(int ac, char **av)
{
	t_stacks	s;

	if (!parsing(ac, av))
		return (0);
	if (ac == 2)
		s = ft_init1(av);
	else
		s = ft_init2(ac, av);
	if (!s.a || !s.b)
		return (0);
	if (is_sorted(s))
	{
		free(s.a);
		free(s.b);
		return (0);
	}
	s = solver(s);
	free(s.a);
	free(s.b);
	return (0);
}
