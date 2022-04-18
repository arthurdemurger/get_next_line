/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 22:12:47 by ademurge          #+#    #+#             */
/*   Updated: 2022/04/18 15:22:47 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*stash_to_line(char *str)
{
	int		size;
	char	*line;
	int		i;

	i = -1;
	size = 0;
	while (str[size] && str[size] != '\n')
		size++;
	line = ft_substr(str, 0, size);
	return (line);
}

char	*clean(char *str)
{
	int	i;

	i = -1;
	while (str && str[++i])
	{
		if (str[i] == '\n' && str[i + 1])
			return (&str[++i]);
		else if (str[i] == '\n')
			return (NULL);
	}
	return (NULL);
}

char	*gnl_free(char *s)
{
	if (s)
		free(s);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		*buf;
	int			n;

	buf = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf || read(fd, NULL, 0) < 0)
		return (gnl_free(buf));
	n = 1;
	while (n && !is_line_break(stash))
	{
		n = read(fd, buf, BUFFER_SIZE);
		stash = gnl_strjoin(stash, buf);
	}
	free(buf);
	line = stash_to_line(stash);
	if (is_line_break(stash) || !n)
		stash = clean(stash);
	return (line);
}

/*
int main (void)
{
	int	fd;
	int	i;

	i = 0;
	fd = open("test.txt", O_RDONLY);
	while (i++ < 15)
		printf("gnl %d : '%s'\n", i, get_next_line(fd));
} */