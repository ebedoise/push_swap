/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIS.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: embedois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:08:48 by embedois          #+#    #+#             */
/*   Updated: 2022/03/25 16:29:27 by embedois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	*ft_cpy(int *tmp, int *a, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		tmp[i] = a[i];
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

t_stacks	prep_lis(t_stacks s)
{
	t_stacks	tmp_s;
	int			*tmp;
	int			i;
	int			save;

	tmp = malloc(sizeof(int) * s.len_a);
	if (!tmp)
		return (s);
	tmp = ft_cpy(tmp, s.a, s.len_a);
	while (tmp[s.len_a - 1] != is_lowest(tmp, s.len_a))
	{
		i = s.len_a;
		save = tmp[s.len_a - 1];
		while (--i > 0)
			tmp[i] = tmp[i - 1];
		tmp[i] = save;
	}
	tmp_s = lis(tmp, s.len_a);
	free(tmp);
	return (tmp_s);
}

t_stacks	get_tmp(t_stacks tmp, int *stack, int len, int j)
{
	int	i;

	i = 0;
	while (i < len)
	{
		tmp.a[0] = stack[i];
		j = i + 1;
		while (j < len)
		{
			if (stack[j] < tmp.a[tmp.len_a - 1])
			{
				tmp.a[tmp.len_a] = stack[j];
				tmp.len_a++;
			}
			j++;
		}
		if (tmp.len_a > tmp.len_b)
		{
			tmp.b = ft_cpy(tmp.b, tmp.a, tmp.len_a);
			tmp.len_b = tmp.len_a;
		}
		tmp.len_a = 1;
		i++;
	}
	return (tmp);
}

t_stacks	lis(int *stack, int len)
{
	t_stacks	tmp;
	int			j;

	j = 0;
	tmp.a = malloc(sizeof(int) * len);
	if (!tmp.a)
		return (tmp);
	tmp.b = malloc(sizeof(int) * len);
	if (!tmp.b)
		return (tmp);
	tmp.len_a = 1;
	tmp.len_b = 0;
	tmp = get_tmp(tmp, stack, len, j);
	return (tmp);
}
