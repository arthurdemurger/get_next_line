/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 22:13:40 by ademurge          #+#    #+#             */
/*   Updated: 2022/04/18 15:17:14 by ademurge         ###   ########.fr       */
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
# define BUFFER_SIZE 1
#endif

/*
**	TO FUCKING DELETE !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
*/

# define ICI printf("ici\n");
# define STASH printf("stash : '%s'\n", stash); 
# define LINE printf("line : '%s'\n", line);
# define BUF printf("buf : '%s'\n", buf);
# define STR printf("str : '%s'\n", str);
# define SIZE printf("size : '%d'\n", size);

/*
**	Utils functions
*/

void	ft_bzero(void *s, size_t n);
int		ft_strlen(char *s);
char	*ft_strdup(char *src);
char	*gnl_strjoin(char *s1, char *s2);
int		is_line_break(char *str);
char	*ft_substr(char const *s, int start, int len);

#endif