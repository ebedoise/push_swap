/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: embedois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:35:44 by embedois          #+#    #+#             */
/*   Updated: 2022/02/21 16:58:06 by embedois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

t_stacks	for_the_norm(t_stacks s)
{
	s = ft_putmove("ra\n", s, 6);
	s = ft_putmove("ra\n", s, 6);
	s = ft_putmove("pa\n", s, 4);
	s = ft_putmove("rra\n", s, 9);
	s = ft_putmove("rra\n", s, 9);
	return (s);
}

t_stacks	solve5(t_stacks s)
{
	s = ft_putmove("pb\n", s, 5);
	s = solve4(s);
	if (s.b[s.len_b - 1] < s.a[s.len_a - 1])
		s = ft_putmove("pa\n", s, 4);
	else if (s.b[s.len_b - 1] < s.a[s.len_a - 2])
	{
		s = ft_putmove("ra\n", s, 6);
		s = ft_putmove("pa\n", s, 4);
		s = ft_putmove("rra\n", s, 9);
	}
	else if (s.b[s.len_b - 1] < s.a[s.len_a - 3])
		s = for_the_norm(s);
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
