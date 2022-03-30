/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: embedois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 13:07:45 by embedois          #+#    #+#             */
/*   Updated: 2022/03/30 14:37:30 by embedois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

t_stacks	solver(t_stacks s)
{
	if (s.len_a == 2)
		s = solve2(s);
	else if (s.len_a == 3)
		s = solve3(s);
	else if (s.len_a == 4)
		s = solve4(s);
	else if (s.len_a == 5)
		s = solve5(s);
	else if (s.len_a > 5)
		s = bigsolver(s);
	return (s);
}

t_stacks	solve2(t_stacks s)
{
	if (s.a[0] < s.a[1])
		s = ft_putmove("sa\n", s, 1);
	return (s);
}

t_stacks	solve3(t_stacks s)
{
	if (s.a[0] > s.a[1] && s.a[1] > s.a[2])
		return (s);
	else if (s.a[0] < s.a[1] && s.a[1] < s.a[2])
	{
		s = ft_putmove("ra\n", s, 6);
		s = ft_putmove("sa\n", s, 1);
	}
	else if (s.a[0] < s.a[1] && s.a[0] < s.a[2])
		s = ft_putmove("rra\n", s, 9);
	else if (s.a[0] > s.a[1] && s.a[0] < s.a[2])
		s = ft_putmove("ra\n", s, 6);
	else if (s.a[0] > s.a[1] && s.a[0] > s.a[2])
		s = ft_putmove("sa\n", s, 1);
	else if (s.a[0] < s.a[1] && s.a[0] > s.a[2])
	{
		s = ft_putmove("sa\n", s, 1);
		s = ft_putmove("ra\n", s, 6);
	}
	return (s);
}

t_stacks	solve4(t_stacks s)
{
	s = smallest(s);
	s = ft_putmove("pb\n", s, 5);
	s = solve3(s);
	s = ft_putmove("pa\n", s, 4);
	return (s);
}

t_stacks	smallest(t_stacks s)
{
	int	i;

	i = 0;
	while (s.a[i] != is_lowest(s.a, s.len_a))
		i++;
	if (i >= s.len_a / 2)
	{
		while (s.a[s.len_a - 1] != is_lowest(s.a, s.len_a))
			s = ft_putmove("ra\n", s, 6);
	}
	else
	{
		while (s.a[s.len_a - 1] != is_lowest(s.a, s.len_a))
			s = ft_putmove("rra\n", s, 9);
	}
	return (s);
}
