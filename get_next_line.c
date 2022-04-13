/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 22:12:47 by ademurge          #+#    #+#             */
/*   Updated: 2022/04/13 19:40:04 by ademurge         ###   ########.fr       */
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
	line = (char *)malloc(sizeof(char) * (size + 1));
	if (!line)
		return (NULL);
	while (++i < size)
	{
		line[i] = str[i];
	}
	line[size] = 0;
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

char	*ft_read(int fd, char *stash, int *n)
{
	char	*buf;
	
	buf = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	*n = read(fd, buf, BUFFER_SIZE);
	if (n < 0)
	{
		free(buf);
		return(NULL);
	}
	stash = strcat_gnl(stash, buf);
	free(buf);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	int			n;
	
	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	stash = ft_read(fd, stash, &n);
	if (!stash)
			return (NULL);
	while (n && !is_line_break(stash))
	{
		stash = ft_read(fd, stash, &n);
		if (!stash)
			return (NULL);
	}
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
	while (i++ < 10)
		printf("gnl %d : '%s'\n", i, get_next_line(fd));
}*/