/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigsolver_bis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: embedois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:04:42 by embedois          #+#    #+#             */
/*   Updated: 2022/02/21 16:42:36 by embedois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	is_in_lis(int n, t_stacks lis_var)
{
	int	i;

	i = 0;
	while (i < lis_var.len_b)
	{
		if (n == lis_var.b[i])
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
	while (s.len_a - i >= s.len_a / 2)
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

int	final_order(t_stacks s)
{
	int	i;
	int	j;

	i = 0;
	while (s.a[s.len_a - 1] != is_lowest(s.a, s.len_a))
	{
		s = ft_rotate(s, 'a');
		i++;
	}
	j = i;
	while (j > 0)
	{
		s = ft_reverse_rotate(s, 'a');
		j--;
	}
	if (i <= s.len_a / 2)
		return (1);
	return (2);
}
