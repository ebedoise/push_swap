/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigsolver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: embedois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:16:06 by embedois          #+#    #+#             */
/*   Updated: 2022/02/10 19:03:51 by embedois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	*ft_cpy(int *tmp, t_stacks s)
{
	int	i;

	i = 0;
	while (i < s.len_a)
	{
		tmp[i] = s.a[i];
		i++;
	}
	return (tmp);
}

int	is_lowest(int *array, int len)
{
	int	tmp;
	int	i;

	i = 1;
	tmp = array[0];
	while (i < len)
	{
		if (array[i] < tmp)
			tmp = array[i];
		i++;
	}
	return (tmp);
}

t_stacks	bigsolver(t_stacks s)
{
	int	*tmp;
	int	i;
	int	save;

	tmp = malloc(sizeof(int) * s.len_a);
	if (!tmp)
		return (s);
	tmp = ft_cpy(tmp, s);
	while (tmp[s.len_a - 1] != is_lowest(tmp, s.len_a))
	{
		i = s.len_a;
		save = tmp[s.len_a - 1];
		while (--i > 0)
			tmp[i] = tmp[i - 1];
		tmp[i] = save;
	}
	free(tmp);
	return (s);
}
