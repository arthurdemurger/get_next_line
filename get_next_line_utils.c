/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 22:13:28 by ademurge          #+#    #+#             */
/*   Updated: 2022/04/18 18:26:04 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	is_line_break(char *str)
{
	while (str && *str)
		if (*str++ == '\n')
			return (1);
	return (0);
}

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

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*dst;
	int		size_s1;
	int		size_s2;
	int		i;

	if (!s1)
		return (ft_strdup(s2));
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	dst = (char *)malloc(sizeof(char) * (size_s1 + size_s1 + 1));
	if (!dst)
		return (NULL);
	i = -1;
	while (++i < size_s1)
		dst[i] = s1[i];
	i--;
	while (++i - size_s1 < size_s2)
		dst[i] = s2[i - size_s1];
	dst[i] = 0;
	free(s1);
	return (dst);
}

char	*gnl_substr(char const *s, int start, int len)
{
	char	*src;
	char	*str;
	int		i;

	if (!s)
		return (NULL);
	src = (char *)s;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (++i < len)
		str[i] = src[start + i];
	str[i] = 0;
	return (str);
}
