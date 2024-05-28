/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42poto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:22:48 by rde-fari          #+#    #+#             */
/*   Updated: 2024/05/28 15:21:38 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*ptr;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ptr = file_reader(ptr, fd);
	if (!ptr)
	{
		free(ptr);
		return (NULL);
	}
	line = get_line(ptr);
	ptr = remaining(ptr);
	return (line);
}

char	*file_reader(char *ptr, int fd)
{
	char	*temp_ptr;
	int		read_return;

	temp_ptr = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!temp_ptr)
		return (NULL);
	read_return = 1;
	while (!nline_scan(ptr, '\n') && read_return > 0)
	{
		read_return = read(fd, temp_ptr, BUFFER_SIZE);
		if (read_return < 0)
		{
			if (ptr)
				free(ptr);
			free(temp_ptr);
			return (NULL);
		}
		temp_ptr[read_return] = '\0';
		ptr = ft_strjoin(ptr, temp_ptr);
	}
	free(temp_ptr);
	return (ptr);
}

char	*get_line(char	*ptr)
{
	char	*str;
	int		i;
	int		j;

	if (ptr[0] == '\0')
		return (NULL);
	i = 0;
	while (ptr[i] && ptr[i] != '\n')
		i++;
	j = i;
	if (ptr[i] == '\n')
		j++;
	str = ft_calloc(j + 1, sizeof(char));
	if (!str)
		return (NULL);
	ft_strcpy(ptr, str, 1);
	return (str);
}

char	*remaining(char *ptr)
{
	char	*remaining;
	int		i;

	i = 0;
	while (ptr[i] && ptr[i] != '\n')
		i++;
	if (ptr[i] == '\0')
	{
		free(ptr);
		return (NULL);
	}
	i++;
	remaining = ft_calloc(ft_strlen(ptr + i) + 1, sizeof(char));
	if (!remaining)
		return (NULL);
	ft_strcpy(ptr + i, remaining, 0);
	free(ptr);
	return (remaining);
}
