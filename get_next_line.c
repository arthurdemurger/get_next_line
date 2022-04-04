/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 22:12:47 by ademurge          #+#    #+#             */
/*   Updated: 2022/03/25 22:18:24 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*dst;

	if (!s1)
	{
		dst = (char *)malloc(sizeof(char) * (ft_strlen(s2) + 1));
		if (!dst)
			return (NULL);
		ft_strcpy(dst, s2);
		return (dst);
	}
	else
	{
		dst = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
		if (!dst)
			return (NULL);
		ft_strcpy(dst, s1);
		if (s2)
			ft_strcat(dst, s2);
		return (dst);
	}
	
}

char	*clean(char *str)
{
	int	i;

	i = -1;
	while (str && str[++i])
		if (str[i] == '\n' && str[i + 1])
			return (&str[++i]);
		else if(str[i] == '\n' && !str[i + 1])
			return (NULL);
	return (str);
}

char	*ft_read(int fd, char *buf)
{
	int			n;

	n = read(fd, buf, BUFFER_SIZE);
	if (n < 0)
		return (NULL);
	return (buf);
}

char	*get_next_line(int fd)
{
	char		*str;
	char		*buf;
	static char	*saved;

	str = NULL;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	ft_read(fd, buf);
	str = ft_strjoin_gnl(saved, buf);
	while (!is_return(buf))
	{
		ft_read(fd, buf);
		str = ft_strjoin_gnl(str, buf);
	}
	saved = clean(buf);
	return (str);
}
