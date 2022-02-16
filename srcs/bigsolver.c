/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigsolver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: embedois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:16:06 by embedois          #+#    #+#             */
/*   Updated: 2022/02/16 18:20:22 by embedois         ###   ########.fr       */
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

t_stacks	bigsolver(t_stacks s)
{
	t_stacks	lis;
	int	i;

	i = 0;
	lis = prepLIS(s);
	while (i < s.len_a)
	{
		if (!is_in_LIS(s.a[i], lis))
			s = ft_putmove("pb\n", s, 5);
		s = ft_putmove("ra\n", s, 6);
		i++;
	}
	return (s);
}
