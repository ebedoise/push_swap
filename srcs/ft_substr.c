/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: embedois <embedois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:41:11 by embedois          #+#    #+#             */
/*   Updated: 2022/02/09 16:25:52 by embedois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

size_t	ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_subsub(void)
{
	char	*array;

	array = malloc(sizeof(char));
	if (!array)
		return (NULL);
	array[0] = '\0';
	return (array);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*array;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	if (start > ft_strlen(s))
	{
		array = ft_subsub();
		return (array);
	}
	array = malloc(sizeof(char) * (len + 1));
	if (!array)
		return (NULL);
	while (s[start + i] && i < len)
	{
		array[i] = s[(size_t)start + i];
		i++;
	}
	array[i] = '\0';
	return (array);
}
