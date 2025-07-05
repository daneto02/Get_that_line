/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daneto <daneto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 08:56:23 by vloureir          #+#    #+#             */
/*   Updated: 2025/06/27 16:39:16 by daneto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		i;
	int		fd;
	char	*line;

	if (argc == 2)
	{
		i = 1;
		fd = open(argv[1], O_RDONLY);
		while (i <= 25)
		{
			line = get_next_line(fd);
			printf("line %d: \n", i);
			printf("%s", line);
			free(line);
			i++;
		}
		close(fd);
	}
	return (0);
}
