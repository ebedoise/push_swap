/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: embedois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:49:35 by embedois          #+#    #+#             */
/*   Updated: 2022/02/10 13:07:00 by embedois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

t_stacks	ft_swap(t_stacks s, char c)
{
	int	tmp;

	if (c == 'a')
	{
		tmp = s.a[s.len_a - 1];
		s.a[s.len_a - 1] = s.a[s.len_a - 2];
		s.a[s.len_a - 2] = tmp;
	}
	if (c == 'b')
	{
		tmp = s.a[s.len_a - 1];
		s.a[s.len_a - 1] = s.a[s.len_a - 2];
		s.a[s.len_a - 2] = tmp;
	}
	if (c == 's')
	{
		s = ft_swap(s, 'a');
		s = ft_swap(s, 'b');
	}
	return (s);
}

t_stacks	ft_push(t_stacks s, char c)
{
	if (c == 'a')
	{
		s.a[s.len_a] = s.b[s.len_b - 1];
		s.len_a++;
		s.len_b--;
	}
	if (c == 'b')
	{
		s.b[s.len_b] = s.a[s.len_a - 1];
		s.len_b++;
		s.len_a--;
	}
	return (s);
}

t_stacks	ft_rotate(t_stacks s, char c)
{
	int	tmp;
	int	i;

	if (c == 'a')
	{
		i = s.len_a;
		tmp = s.a[s.len_a - 1];
		while (--i > 0)
			s.a[i] = s.a[i - 1];
		s.a[i] = tmp;
	}
	if (c == 'b')
	{
		i = s.len_b;
		tmp = s.b[s.len_b - 1];
		while (--i > 0)
			s.b[i] = s.b[i - 1];
		s.b[i] = tmp;
	}
	if (c == 'r')
	{
		s = ft_rotate(s, 'a');
		s = ft_rotate(s, 'b');
	}
	return (s);
}

t_stacks	ft_reverse_rotate(t_stacks s, char c)
{
	int	tmp;
	int	i;

	i = -1;
	if (c == 'a')
	{
		tmp = s.a[0];
		while (++i < s.len_a - 1)
			s.a[i] = s.a[i + 1];
		s.a[i] = tmp;
	}
	if (c == 'b')
	{
		tmp = s.b[0];
		while (++i < s.len_b - 1)
			s.b[i] = s.b[i + 1];
		s.b[i] = tmp;
	}
	if (c == 'r')
	{
		s = ft_reverse_rotate(s, 'a');
		s = ft_reverse_rotate(s, 'b');
	}
	return (s);
}
