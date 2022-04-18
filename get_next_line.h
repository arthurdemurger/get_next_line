/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 22:13:40 by ademurge          #+#    #+#             */
/*   Updated: 2022/04/18 23:57:07 by ademurge         ###   ########.fr       */
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

char	*get_next_line(int fd);

/*
**	Define constants
*/

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

/*
**	TO FUCKING DELETE !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
*/
# include <string.h>
# define ICI printf("ici\n");
# define STASH printf("stash : '%s'\n", stash); 
# define LINE printf("line : '%s'\n", line);
# define BUF printf("buf : '%s'\n", buf);
# define STR printf("str : '%s'\n", str);
# define SIZE printf("size : '%d'\n", size);
# define N printf("n : '%d'\n", n);

/*
**	Utils functions
*/

int		ft_strlen(char *s);
char	*ft_strdup(char *src);
char	*gnl_strjoin(char *s1, char *s2);
int		is_line_break(char *str);
char	*gnl_substr(char const *s, int start, int len);

#endif