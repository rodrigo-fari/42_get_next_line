/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42poto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:22:48 by rde-fari          #+#    #+#             */
/*   Updated: 2024/05/22 19:35:23 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr(const char *s, int c);

char	*get_next_line(int fd)
{
/* 	static char	*storage; */
	const char	*storage;
	char		*line;
	int			read_return;

	line = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (!line)
		return (NULL);
	read_return = read(fd, line, BUFFER_SIZE);
	while (ft_strchr(line, '\0') != 0)
		storage = ft_strjoin(storage, line);
	printf("Resultado atual: %s\n", storage);
	return (line);
}

int	ft_strchr(const char *s, int c)
{
	while ((*s != '\0') && (*s != c))
	{
		s++;
	}
	if (*s == c)
	{
		return (1);
	}
	return (0);
}

/* char	*ft_strdup(const char *s)
{
	int		i;
	int		size;
	char	*dup;

	size = ft_strlen(s);
	dup = malloc((sizeof(char) * size) + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	if (i == size)
		dup[i] = '\0';
	return (dup);
} */

/* size_t	ft_strlen(const char *str)
{
	size_t		i;
	const char	*s;

	s = str;
	i = 0;
	while (s[i])
		i++;
	return (i);
} */

/* char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substr;

	if (!s || start >= ft_strlen(s) || len == 0)
		return (ft_strdup(""));
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	substr = malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		substr[i] = s[start + i];
		i++;
	}
	return (substr);
} */

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

int main(void)
{
/*  	char	*line;
	int		i;
	int		fd1;
	int		fd2;
	int		fd3;


	fd1 = open("text1.txt", O_RDONLY);
	fd2 = open("text2.txt", O_RDONLY);
	fd3 = open("text3.txt", O_RDONLY);
	
	i = 1;
	while (i < 7)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd2);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd3);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd1);
	close(fd2);
	close(fd3); */
	int fd1 = open("text1.txt", O_RDONLY );
	get_next_line(fd1);
	return (0);
}
