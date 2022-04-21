/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 22:13:40 by ademurge          #+#    #+#             */
/*   Updated: 2022/04/19 13:48:01 by ademurge         ###   ########.fr       */
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

/*
**	Utils functions
*/

int		is_line_break(char *str);
int		ft_strlen(char *s);
char	*ft_strdup(char *src);
char	*gnl_strjoin(char *s1, char *s2);
char	*gnl_substr(char const *s, int start, int len);

/*
** get_next_line function
*/

char	*get_next_line(int fd);

#endif