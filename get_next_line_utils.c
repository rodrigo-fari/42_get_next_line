/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42poto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:23:08 by rde-fari          #+#    #+#             */
/*   Updated: 2024/05/21 18:14:03 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*strjoin;
	size_t			malloc_size;
	size_t			i;
	size_t			j;

	malloc_size = ((ft_strlen(s1) + ft_strlen(s2)) + 1);
	strjoin = malloc(sizeof(char) * malloc_size);
	if (!strjoin)
		return (NULL);
	i = 0;
	while (i < (ft_strlen((const char *)s1)))
	{
		strjoin[i] = s1[i];
		i++;
	}
	j = 0;
	while (i < (malloc_size - 1))
	{
		strjoin[i] = s2[j];
		i++;
		j++;
	}
	strjoin[i] = '\0';
	return (strjoin);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if ((char)c == '\0')
		return ((char *)&s[i]);
	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	return (NULL);
}
