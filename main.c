/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clemo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 19:14:53 by clemo             #+#    #+#             */
/*   Updated: 2020/09/18 19:17:51 by clemo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int		main(void)
{
	char	*line;
	int		fd;

	fd = open("compile_flags.txt", O_RDONLY);
	while (get_next_line(fd, &line))
		printf("|%s|\n", line);
}
