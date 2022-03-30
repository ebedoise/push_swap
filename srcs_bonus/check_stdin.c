/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stdin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: embedois <embedois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:57:06 by embedois          #+#    #+#             */
/*   Updated: 2022/03/30 14:27:53 by embedois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

t_stacks	resolve(t_stacks s, char *str)
{
	if (ft_strcmp(str, "sa\n") == 0)
		return (ft_swap(s, 'a'));
	else if (ft_strcmp(str, "sb\n") == 0)
		return (ft_swap(s, 'b'));
	else if (ft_strcmp(str, "ss\n") == 0)
		return (ft_swap(s, 's'));
	else if (ft_strcmp(str, "pa\n") == 0)
		return (ft_push(s, 'a'));
	else if (ft_strcmp(str, "pb\n") == 0)
		return (ft_push(s, 'b'));
	else if (ft_strcmp(str, "ra\n") == 0)
		return (ft_rotate(s, 'a'));
	else if (ft_strcmp(str, "rb\n") == 0)
		return (ft_rotate(s, 'b'));
	else if (ft_strcmp(str, "rr\n") == 0)
		return (ft_rotate(s, 'r'));
	else if (ft_strcmp(str, "rra\n") == 0)
		return (ft_reverse_rotate(s, 'a'));
	else if (ft_strcmp(str, "rrb\n") == 0)
		return (ft_reverse_rotate(s, 'b'));
	else if (ft_strcmp(str, "rrr\n") == 0)
		return (ft_reverse_rotate(s, 'r'));
	return (s);
}

int	is_move(char *str)
{
	if (ft_strcmp(str, "sa\n") == 0)
		return (1);
	else if (ft_strcmp(str, "sb\n") == 0)
		return (1);
	else if (ft_strcmp(str, "ss\n") == 0)
		return (1);
	else if (ft_strcmp(str, "pa\n") == 0)
		return (1);
	else if (ft_strcmp(str, "pb\n") == 0)
		return (1);
	else if (ft_strcmp(str, "ra\n") == 0)
		return (1);
	else if (ft_strcmp(str, "rb\n") == 0)
		return (1);
	else if (ft_strcmp(str, "rr\n") == 0)
		return (1);
	else if (ft_strcmp(str, "rra\n") == 0)
		return (1);
	else if (ft_strcmp(str, "rrb\n") == 0)
		return (1);
	else if (ft_strcmp(str, "rrr\n") == 0)
		return (1);
	return (0);
}

int	check_stdin(t_stacks s)
{
	char	*str;

	str = get_next_line(0);
	while (str)
	{
		if (!is_move(str))
		{
			free(str);
			get_next_line(42);
			return (0);
		}
		s = resolve(s, str);
		free(str);
		str = get_next_line(0);
	}
	free(str);
	if (is_sorted(s) && s.len_b == 0)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	get_next_line(42);
	return (1);
}
