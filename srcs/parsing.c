/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: embedois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:05:55 by embedois          #+#    #+#             */
/*   Updated: 2022/02/09 17:52:28 by embedois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	is_int(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	if (ft_atoli(str) > 2147483647 || ft_atoli(str) < -2147483648)
		return (0);
	return (1);
}

int	is_list(char *str)
{
	char	**array;
	int		len;

	len = n_words(str, ' ');
	array = ft_split(str, ' ');
	if (!array)
		return (0);
	if (!parse(len, array))
	{
		ft_free_split(array, len);
		return (0);
	}
	ft_free_split(array, len);
	return (1);
}

int	parse(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (i < ac)
	{
		j = i + 1;
		if (!is_int(av[i]))
			return (0);
		while (j < ac)
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	parsing(int ac, char **av)
{
	if (ac <= 1)
		return (0);
	if (ac == 2)
	{
		if (is_int(av[1]))
			return (0);
		else if (is_list(av[1]))
			return (1);
		else
			return (print_error());
	}
	if (!parse(ac - 1, av + 1))
		return (print_error());
	return (1);
}
