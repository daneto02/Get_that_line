/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daneto <daneto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 10:37:41 by daneto            #+#    #+#             */
/*   Updated: 2025/07/05 15:34:36 by daneto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int			i;
	char		*line;
	static char	buffer[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	i = 0;
	line = NULL;
	line = ft_read_and_join(fd, buffer);
	if (line)
	{
		while (line[i] && line[i] != '\n')
			i++;
		if (line[i] == '\n')
			i++;
		line[i] = '\0';
	}
	clean_buffer(buffer);
	return (line);
}
