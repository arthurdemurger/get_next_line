/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 22:12:47 by ademurge          #+#    #+#             */
/*   Updated: 2022/03/21 19:59:35 by ademurge         ###   ########.fr       */
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
	dst = ft_strcat(s1, s2);
	return (dst);
}

char	*get_next_line(int fd)
{
	static char	*str;
	int			n;
	char		*buf;
	int			i;

	i = 0;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	n = read(fd, buf, BUFFER_SIZE);
	if (n < 0)
		return (NULL);
	str = ft_strjoin_gnl(str, buf);
	while (!is_return(buf))
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n < 0)
			return (NULL);
		str = ft_strjoin_gnl(str, buf);
		i++;
	}
	return (str);
}
