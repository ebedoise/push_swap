/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigsolver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: embedois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:16:06 by embedois          #+#    #+#             */
/*   Updated: 2022/02/21 18:34:23 by embedois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

t_stacks	let_me_iin(t_stacks s, int save[2])
{
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
	s = let_me_iin(s, save);
	return (s);
}

void	get_save(int save[2], int tmp[2], t_stacks s)
{
	int	i;

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
	get_save(save, tmp, s);
	s = let_me_in(s, save);
	return (s);
}

t_stacks	bigsolver(t_stacks s)
{
	t_stacks	lis_var;
	int			i;

	i = s.len_a - 1;
	lis_var = prep_lis(s);
	while (i-- >= 0)
	{
		if (!is_in_lis(s.a[s.len_a - 1], lis_var))
			s = ft_putmove("pb\n", s, 5);
		else
			s = ft_putmove("ra\n", s, 6);
	}
	while (s.len_b != 0)
		s = best_move(s);
	if (final_order(s) == 1)
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
