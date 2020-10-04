/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clemo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 19:14:53 by clemo             #+#    #+#             */
/*   Updated: 2020/09/19 11:45:50 by clemo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int		main(int ac, char **av)
{
	char	*line;
	int		fd;
	int		res;
	int		total;
	int		i;

	if (ac == 1)
	{
		while (get_next_line(0, &line) > 0)
		{
			printf("|%s|\n", line);
			free(line);
		}
		return (0);
	}
	i = 1;
	while (i < ac)
	{
		fd = open(av[i], O_RDONLY);
		total = 0;
		while ((res = get_next_line(fd, &line)) > 0)
		{
			printf("|%s| res : %i\n", line, res);
			total += res;
		}
		printf("|%s| res : %i\n", line, res);
		printf("total : %i\n", total);
		close(fd);
		i++;
	}
}
