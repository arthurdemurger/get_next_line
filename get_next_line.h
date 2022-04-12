/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 22:13:40 by ademurge          #+#    #+#             */
/*   Updated: 2022/04/12 17:10:09 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

/*
**	Libraries
*/

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

/*
**	Define constants
*/

# define MALLOC_ERROR 2
# define READ_ERROR 3
# define BUFFER_SIZE 10

///*
//**	TO FUCKING DELETE !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//*/
//
//# define ICI printf("ici\n");
//# define STASH printf("stash : '%s'\n", stash); 
//# define LINE printf("line : '%s'\n", line);
//# define BUF printf("buf : '%s'\n", buf);
//# define STR printf("str : '%s'\n", str);
//# define SIZE printf("size : '%d'\n", size);
//
/*
**	Utils functions
*/

int		ft_strlen(char *s);
char	*ft_strdup(char *src);
char	*strcat_gnl(char *dest, char *src);
int		is_line_break(char *str);

#endif