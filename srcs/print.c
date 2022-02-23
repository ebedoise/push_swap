/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: embedois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:06:56 by embedois          #+#    #+#             */
/*   Updated: 2022/02/23 19:56:50 by embedois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

t_stacks	ft_putmove(char *str, t_stacks s, int n)
{
	ft_putstr(str);
	if (n == 1)
		s = ft_swap(s, 'a');
	if (n == 2)
		s = ft_swap(s, 'b');
	if (n == 3)
		s = ft_swap(s, 's');
	if (n == 4)
		s = ft_push(s, 'a');
	if (n == 5)
		s = ft_push(s, 'b');
	if (n == 6)
		s = ft_rotate(s, 'a');
	if (n == 7)
		s = ft_rotate(s, 'b');
	if (n == 8)
		s = ft_rotate(s, 'r');
	if (n == 9)
		s = ft_reverse_rotate(s, 'a');
	if (n == 10)
		s = ft_reverse_rotate(s, 'b');
	if (n == 11)
		s = ft_reverse_rotate(s, 'r');
	return (s);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
	return (1);
}

int	print_error(void)
{
	write(2, "Error\n", 6);
	return (0);
}
