/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: embedois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 14:14:33 by embedois          #+#    #+#             */
/*   Updated: 2022/02/25 14:30:25 by embedois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

char	*first_join(char *s2, size_t car)
{
	size_t	i;
	char	*array;

	i = 0;
	array = malloc(sizeof(char) * (ft_strlen(s2) + 1));
	if (!array)
		return (NULL);
	while (s2[i] && i < car)
	{
		array[i] = s2[i];
		i++;
	}
	array[i] = '\0';
	return (array);
}

char	*ft_strjoin(char *s1, char *s2, size_t car)
{
	size_t	i;
	char	*array;

	i = 0;
	if (!s1)
		return (first_join(s2, car));
	else
		array = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!array)
		return (NULL);
	while (s1[i])
	{
		array[i] = s1[i];
		i++;
	}
	while (s2[i - ft_strlen(s1)] && i - ft_strlen(s1) < car)
	{
		array[i] = s2[i - ft_strlen(s1)];
		i++;
	}
	array[i] = '\0';
	return (array);
}
