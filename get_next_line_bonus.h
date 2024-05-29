/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42poto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:55:08 by rde-fari          #+#    #+#             */
/*   Updated: 2024/05/29 16:19:50 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

//---------BUFFER_SIZE----------//

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# ifndef MAX_FD
#  define MAX_FD 1024
# endif

//---------Librarys----------//

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

//---------Get Next Line Functions---------//

char	*get_esp_line(char	*ptr);
char	*remaining(char *ptr);
char	*get_next_line(int fd);
char	*file_reader(char *ptr, int fd);

//---------Get Next Line Utils Functions---------//

int		nline_scan(char *str, int c);

size_t	ft_strlen(char *str);

void	*ft_calloc(size_t nmemb, size_t size);

char	*ft_strjoin(char *str1, char *str2);
char	*ft_strcpy(char *src, char *dest, int param);

//---------End If---------//

#endif