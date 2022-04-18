/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 22:12:47 by ademurge          #+#    #+#             */
/*   Updated: 2022/04/19 00:34:30 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*gnl_free(char *s)
{
	if (s)
		free(s);
	return (NULL);
}

char	*stash_to_line(char *str)
{
	int		size;
	char	*line;

	size = 0;
	if (!*str)
		return (NULL);
	while (str[size] && str[size] != '\n')
		size++;
	line = gnl_substr(str, 0, size + 1);
	return (line);
}

char	*clean(char *stash, int n)
{
	char	*str;
	int		i;

	i = -1;
	if (!n)
		return (gnl_free(stash));
	while (stash && stash[++i])
	{
		if (stash[i] == '\n' && stash[i + 1])
		{
			str = ft_strdup(&stash[++i]);
			free(stash);
			return (str);
		}
		else if (stash[i] == '\n')
			return (gnl_free(stash));
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*stash[OPEN_MAX];
	char		*line;
	char		*buf;
	int			n;

	buf = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf || read(fd, NULL, 0) < 0)
		return (gnl_free(buf));
	n = 42;
	while (n && !is_line_break(stash[fd]))
	{
		n = read(fd, buf, BUFFER_SIZE);
		buf[n] = 0;
		stash[fd] = gnl_strjoin(stash[fd], buf);
		if (!stash[fd])
			return (gnl_free(buf));
	}
	free(buf);
	line = stash_to_line(stash[fd]);
	stash[fd] = clean(stash[fd], n);
	return (line);
}
