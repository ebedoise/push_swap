/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: embedois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:35:44 by embedois          #+#    #+#             */
/*   Updated: 2022/03/30 10:41:44 by embedois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

t_stacks	solve5(t_stacks s)
{
	s = smallest(s);
	s = ft_putmove("pb\n", s, 5);
	s = smallest(s);
	s = ft_putmove("pb\n", s, 5);
	s = solve3(s);
	s = ft_putmove("pa\n", s, 4);
	s = ft_putmove("pa\n", s, 4);
	return (s);
}
