/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daneto <daneto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 10:37:34 by daneto            #+#    #+#             */
/*   Updated: 2025/07/09 11:57:57 by daneto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*buffer;

	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	buffer = malloc(sizeof(char) * (len + 1));
	if (!buffer)
		return (free(s1), NULL);
	while (s1 && s1[i])
		buffer[j++] = s1[i++];
	i = 0;
	while (s2[i])
		buffer[j++] = s2[i++];
	buffer[j] = '\0';
	free(s1);
	return (buffer);
}

char	*ft_read_and_join(int fd, char *buffer)
{
	char	*line;
	int		bytes;

	line = NULL;
	bytes = 1;
	if (buffer[0])
		line = ft_strjoin(line, buffer);
	while (!ft_look_for_nl(buffer, '\n') && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes <= 0)
			break ;
		buffer[bytes] = '\0';
		line = ft_strjoin(line, buffer);
	}
	if (bytes == -1)
	{
		free(line);
		buffer[0] = '\0';
		return (NULL);
	}
	return (line);
}

void	clean_buffer(char *buffer)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	while (buffer[i])
		buffer[j++] = buffer[i++];
	buffer[j] = '\0';
}

char	*ft_look_for_nl(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	return (0);
}
