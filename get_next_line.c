/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 13:24:02 by hhamza            #+#    #+#             */
/*   Updated: 2021/12/19 18:42:36 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	remainder[BUFFER_SIZE + 1];
	char		buffer[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		read_size;
	char		*temp;

	line = ft_strdup(remainder);
	while (ft_indexof(line, '\n') == -1)
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		if (read_size <= 0)
			break ;
		buffer[read_size] = '\0';
		temp = line;
		line = ft_strjoin(line, buffer);
		free(temp);
	}
	if (line[0] == '\0' || read_size == -1)
	{
		free(line);
		return (NULL);
	}
	line = ft_save_remainder(line, remainder);
	return (line);
}

char	*ft_save_remainder(char *line, char *remainder)
{
	ssize_t	endl_index;
	char	*temp;

	endl_index = ft_indexof(line, '\n');
	if (endl_index != -1)
	{
		ft_strlcpy(remainder, line + endl_index + 1, BUFFER_SIZE + 1);
		temp = line;
		line = (char *) malloc(sizeof(char) * (endl_index + 2));
		if (line == NULL)
			return (NULL);
		ft_strlcpy(line, temp, endl_index + 2);
		free(temp);
	}
	else
		remainder[0] = '\0';
	return (line);
}
