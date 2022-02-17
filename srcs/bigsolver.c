/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigsolver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: embedois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:16:06 by embedois          #+#    #+#             */
/*   Updated: 2022/02/17 17:05:14 by embedois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	is_in_LIS(int n, t_stacks lis)
{
	int	i;

	i = 0;
	while (i < lis.len_b)
	{
		if (n == lis.b[i])
			return (1);
		i++;
	}
	return (0);
}

int	biggest(t_stacks s)
{
	int	i;
	int	tmp;

	i = s.len_a - 2;
	tmp = i + 1;
	while (i >= 0)
	{
		if (s.a[i] > s.a[tmp])
			tmp = i;
		i--;
	}
	if (tmp < s.len_a / 2)
		return (tmp * -1);
	else if (tmp >= s.len_a / 2)
		return (s.len_a - tmp);
	return (0);
}

int	pos_in_a(t_stacks s, int n)
{
	int	i;

	i = 1;
	if (n < s.a[s.len_a - 1] && n > s.a[0])
		return (0);
	while (s.len_a - i > s.len_a / 2)
	{
		if (n > s.a[s.len_a - i] && n < s.a[s.len_a - 1 - i])
			return (i);
		i++;
	}
	i = 1;
	while (i < s.len_a / 2)
	{
		if (n < s.a[i - 1] && n > s.a[i])
			return (i * -1);
		i++;
	}
	return (biggest(s));
}

int	ft_abs_moves(int a, int b)
{
	if (a < 0 && b < 0)
	{
		if (a < b)
			return (-a);
		return (-b);
	}
	if (a > 0 && b > 0)
	{
		if (a > b)
			return (a);
		return (b);
	}
	if (a < 0)
		a *= -1;
	if (b < 0)
		b *= -1;
	return (a + b);
}

t_stacks	let_me_in(t_stacks s, int save[2])
{
	while (save[0] < 0 && save[1] < 0)
	{
		s = ft_putmove("rrr\n", s, 11);
		save[0]++;
		save[1]++;
	}
	while (save[0] > 0 && save[1] > 0)
	{
		s = ft_putmove("rr\n", s, 8);
		save[0]--;
		save[1]--;
	}
	while (save[0] > 0)
	{
		s = ft_putmove("ra\n", s, 6);
		save[0]--;
	}
	while (save[0] < 0)
	{
		s = ft_putmove("rra\n", s, 9);
		save[0]++;
	}
	while (save[1] < 0)
	{
		s = ft_putmove("rrb\n", s, 10);
		save[1]++;
	}
	while (save[1] > 0)
	{
		s = ft_putmove("rb\n", s, 7);
		save[1]--;
	}
	s = ft_putmove("pa\n", s, 4);
	return (s);
}

t_stacks	best_move(t_stacks s)
{
	int	save[2];
	int	tmp[2];
	int	i;

	i = s.len_b - 1;
	save[0] = 1000;
	save[1] = 1000;
	while (i >= s.len_b / 2)
	{
		tmp[1] = s.len_b - 1 - i;
		tmp[0] = pos_in_a(s, s.b[i]);
		if (ft_abs_moves(tmp[0], tmp[1]) < ft_abs_moves(save[0], save[1]))
		{
			save[0] = tmp[0];
			save[1] = tmp[1];
		}
		i--;
	}
	i = 1;
	while (i - 1 < s.len_b / 2)
	{
		tmp[1] = -1 * i;
		tmp[0] = pos_in_a(s, s.b[i - 1]);
		if (ft_abs_moves(tmp[0], tmp[1]) < ft_abs_moves(save[0], save[1]))
		{
			save[0] = tmp[0];
			save[1] = tmp[1];
		}
		i++;
	}
	s = let_me_in(s, save);
	return (s);
}

t_stacks	bigsolver(t_stacks s)
{
	t_stacks	lis;
	int	i;

	i = s.len_a - 1;
	lis = prepLIS(s);
	while (i >= 0)
	{
		if (!is_in_LIS(s.a[s.len_a - 1], lis))
			s = ft_putmove("pb\n", s, 5);
		else
			s = ft_putmove("ra\n", s, 6);
		i--;
	}
	while (s.len_b != 0)
		s = best_move(s);
	//add if 2nd half rra
	while (s.a[s.len_a - 1] != is_lowest(s.a, s.len_a))
		s = ft_putmove("ra\n", s, 6);
	return (s);
}
