/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ermatheu <ermatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 12:46:48 by ermatheu          #+#    #+#             */
/*   Updated: 2021/08/26 14:55:08 by ermatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*backup[256];
	char		*buf_read;
	char		*temp;
	int			verification;
	int			aux;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 256)
		return (NULL);
	buf_read = malloc (sizeof(char) * BUFFER_SIZE + 1);
	if (!buf_read)
	{
		free(buf_read);
		return (NULL);
	}
	if (backup[fd])
		temp = backup[fd];
	else
		temp = ft_calloc(1, sizeof(char));
	verification = 1;
	while (verification)
	{
		verification = read (fd, buf_read, BUFFER_SIZE);
		if (verification <= 0 && temp[0] == 0)
		{
			free(temp);
			free(buf_read);
			return (NULL);
		}
		buf_read[verification] = '\0';
		temp = ft_strjoin(temp, buf_read);
		if (!temp)
			return (NULL);
		if (ft_strchr(temp, '\n'))
			break ;
	}
	aux = 0;
	while (temp[aux] != '\n' && temp[aux] != '\0')
		aux++;
	backup[fd] = ft_substr(temp, aux + 1, -1);
	if (temp[0] == '\0')
		free(backup[fd]);
	line = ft_substr(temp, 0, aux + 1);
	free(temp);
	free(buf_read);
	return (line);
}
