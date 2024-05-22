/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42poto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:24:03 by rde-fari          #+#    #+#             */
/*   Updated: 2024/05/22 19:04:54 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

//---------Library----------//

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

//---------Get Next Line Functions---------//

char	*get_next_line(int fd);

//---------End If---------//
#endif