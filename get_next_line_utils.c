/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ermatheu <ermatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 12:56:41 by ermatheu          #+#    #+#             */
/*   Updated: 2021/08/26 15:21:58 by ermatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == '\0' && (char) c == '\0')
		return ((char *)(s + i));
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	int				i;
	unsigned int	len_s;

	i = -1;
	len_s = 0;
	while (s[len_s] != '\0')
		len_s++;
	if (start > len_s)
	{
		sub = (char *)ft_calloc(sizeof(char), 1);
		if (!sub)
			return (NULL);
		return (sub);
	}
	if (len > (len_s - start))
		len = len_s - start;
	sub = malloc(sizeof(char) * len + 1);
	if (sub == NULL)
		return (NULL);
	while ((int)len > ++i)
		sub[i] = s[start + i];
	sub[i] = '\0';
	return (sub);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*alloc;
	size_t	full_size;
	size_t	i;

	i = 0;
	full_size = nmemb * size;
	alloc = malloc(full_size);
	if (alloc == 0)
		return (NULL);
	while (full_size > i)
	{
		alloc[i] = '\0';
		i++;
	}
	return (alloc);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	char	*str;
	int		x;

	i = 0;
	while (s1[i] != '\0')
		i++;
	x = 0;
	while (s2[x] != '\0')
		x++;
	str = malloc(sizeof(char) * (i + x + 1));
	if (!str)
		return (NULL);
	i = -1;
	x = -1;
	while (s1[++i] != '\0')
		str[i] = s1[i];
	while (s2[++x] != '\0')
		str[x + i] = s2[x];
	str[x + i] = '\0';
	free (s1);
	return (str);
}
