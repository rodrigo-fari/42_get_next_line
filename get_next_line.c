/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42poto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:22:48 by rde-fari          #+#    #+#             */
/*   Updated: 2024/05/21 19:05:15 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
*	GET_NEXT_LINE
*	-------------
*	DESCRIPTION
*	This function takes an opened file descriptor and returns its next line.
*	This function has undefined behavior when reading from a binary file.
*	PARAMETERS
*	#1. A file descriptor 
*	RETURN VALUES
*	If successful, get_next_line returns a string with the full line ending in
*	a line break (`\n`) when there is one. 
*	If an error occurs, or there's nothing more to read, it returns NULL.
*	----------------------------------------------------------------------------
*/

#include "get_next_line.h"

// int fd sera sempre sempre a primeira linha de cda arquivo. Semnpre que o programa e executado ele pega a proxima.
//size_t read(int fildes, void *buf, size_t nbyte);
char *get_next_line(int fd)// fd == fd1 (text1.txt).
{
	char	*temp;
	int		buf;
	int		i;

	i = 0;
	while (i != BUFFER_SIZE)
	{
		temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!temp)
			return (NULL);
		buf = read(fd, temp, 5);
		printf("->%s\n", temp);
		free(temp);
		i++;
	}
	return (temp);
}



int main(void)
{
/* 	char	*line;
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
