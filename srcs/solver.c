/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: embedois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 13:07:45 by embedois          #+#    #+#             */
/*   Updated: 2022/02/16 19:37:57 by embedois         ###   ########.fr       */
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
	if (s.a[0] < s.a[1] && s.a[0] > s.a[2])
	{
		s = ft_putmove("ra\n", s, 6);
		s = ft_putmove("sa\n", s, 1);
		s = ft_putmove("rra\n", s, 9);
	}
	if (s.a[2] < s.a[0] && s.a[2] > s.a[1])
		s = ft_putmove("sa\n", s, 1);
	if (s.a[2] > s.a[1] && s.a[1] > s.a[0])
	{
		s = ft_putmove("sa\n", s, 1);
		s = ft_putmove("rra\n", s, 9);
	}
	if (s.a[2] < s.a[1] && s.a[2] > s.a[0])
		s = ft_putmove("rra\n", s, 9);
	if (s.a[2] > s.a[0] && s.a[0] > s.a[1])
		s = ft_putmove("ra\n", s, 6);
	return (s);
}

t_stacks	solve4(t_stacks s)
{
	s = ft_putmove("pb\n", s, 5);
	s = solve3(s);
	if (s.b[s.len_b - 1] < s.a[s.len_a - 1])
		s = ft_putmove("pa\n", s, 4);
	else if (s.b[s.len_b - 1] < s.a[s.len_a - 2])
	{
		s = ft_putmove("ra\n", s, 6);
		s = ft_putmove("pa\n", s, 4);
		s = ft_putmove("rra\n", s, 9);
	}
	else if (s.b[s.len_b - 1] < s.a[0])
	{
		s = ft_putmove("rra\n", s, 9);
		s = ft_putmove("pa\n", s, 4);
		s = ft_putmove("ra\n", s, 6);
		s = ft_putmove("ra\n", s, 6);
	}
	else if (s.b[s.len_b - 1] > s.a[0])
	{
		s = ft_putmove("pa\n", s, 4);
		s = ft_putmove("ra\n", s, 6);
	}
	return (s);
}
