/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 22:13:28 by ademurge          #+#    #+#             */
/*   Updated: 2022/04/12 17:07:38 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*str;
	int		i;

	i = -1;
	str = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!str)
		return (NULL);
	while (src[++i])
		str[i] = src[i];
	str[i] = 0;
	return (str);
}

char	*strcat_gnl(char *dest, char *src)
{
	int	i;
	int	j;

	i = -1;
	if (!dest)
		dest = ft_strdup(src);
	else
	{
		j = ft_strlen(dest);
		while (src[++i])
			dest[j + i] = src[i];
		dest[j + i] = 0;
	}
	return (dest);
}

int	is_line_break(char *str)
{
	while (str && *str)
		if (*str++ == '\n')
			return (1);
	return (0);
}
