/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stdin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: embedois <embedois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:57:06 by embedois          #+#    #+#             */
/*   Updated: 2022/02/25 14:29:28 by embedois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

t_stacks	resolve(t_stacks s, char *str)
{
	if (ft_strcmp(str, "sa") == 0)
		return (ft_swap(s, 'a'));
	else if (ft_strcmp(str, "sb") == 0)
		return (ft_swap(s, 'b'));
	else if (ft_strcmp(str, "ss") == 0)
		return (ft_swap(s, 's'));
	else if (ft_strcmp(str, "pa") == 0)
		return (ft_push(s, 'a'));
	else if (ft_strcmp(str, "pb") == 0)
		return (ft_push(s, 'b'));
	else if (ft_strcmp(str, "ra") == 0)
		return (ft_rotate(s, 'a'));
	else if (ft_strcmp(str, "rb") == 0)
		return (ft_rotate(s, 'b'));
	else if (ft_strcmp(str, "rr") == 0)
		return (ft_rotate(s, 'r'));
	else if (ft_strcmp(str, "rra") == 0)
		return (ft_reverse_rotate(s, 'a'));
	else if (ft_strcmp(str, "rrb") == 0)
		return (ft_reverse_rotate(s, 'b'));
	else if (ft_strcmp(str, "rrr") == 0)
		return (ft_reverse_rotate(s, 'r'));
	return (s);
}

int	is_move(char *str)
{
	if (ft_strcmp(str, "sa") == 0)
		return (1);
	else if (ft_strcmp(str, "sb") == 0)
		return (1);
	else if (ft_strcmp(str, "ss") == 0)
		return (1);
	else if (ft_strcmp(str, "pa") == 0)
		return (1);
	else if (ft_strcmp(str, "pb") == 0)
		return (1);
	else if (ft_strcmp(str, "ra") == 0)
		return (1);
	else if (ft_strcmp(str, "rb") == 0)
		return (1);
	else if (ft_strcmp(str, "rr") == 0)
		return (1);
	else if (ft_strcmp(str, "rra") == 0)
		return (1);
	else if (ft_strcmp(str, "rrb") == 0)
		return (1);
	else if (ft_strcmp(str, "rrr") == 0)
		return (1);
	return (0);
}

int	check_moves(t_stacks s, char **splited, char *save)
{
	int	i;

	i = 0;
	while (splited[i])
	{
		if (!is_move(splited[i]))
		{
			ft_free_split(splited, n_words(save, '\n'));
			return (0);
		}
		i++;
	}
	i = 0;
	while (splited[i])
	{
		s = resolve(s, splited[i]);
		i++;
	}
	if (is_sorted(s) && !s.len_b)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	ft_free_split(splited, n_words(save, '\n'));
	return (1);
}

char	*read_stdin(char *save, int car, char in[1000])
{
	car = read(STDOUT_FILENO, in, 1000);
	if (car == -1)
		return (NULL);
	while (car)
	{
		save = ft_strjoin(save, in, car);
		car = read(STDOUT_FILENO, in, 1000);
		if (car == -1)
			return (NULL);
	}
	return (save);
}

int	check_stdin(t_stacks s)
{
	char	in[1000];
	int		car;
	char	*save;
	char	**splited;

	save = malloc(sizeof(char));
	if (!save)
		return (0);
	save[0] = '\0';
	car = 0;
	save = read_stdin(save, car, in);
	if (!save)
	{
		free(save);
		return (0);
	}
	if (save[ft_strlen(save) - 1] != '\n')
		return (0);
	splited = ft_split(save, '\n');
	free(save);
	if (!splited)
		return (ft_free_split2(splited, n_words(save, '\n')));
	if (!check_moves(s, splited, save))
		return (0);
	return (1);
}
