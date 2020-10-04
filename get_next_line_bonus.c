/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clemo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 18:01:40 by clemo             #+#    #+#             */
/*   Updated: 2020/10/04 13:06:00 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strdup_start_of_line(char *buf, char **line, int len)
{
	int		i;

	if (!(*line = malloc((len + 1) * sizeof(char))))
		return (-1);
	i = 0;
	while (*buf && *buf != '\n')
	{
		line[0][i++] = *buf;
		*(buf++) = -1;
	}
	line[0][i] = 0;
	if (!*buf)
		return (i);
	*buf = -1;
	return (0);
}

/*
**	TODO
**	change dup_start_of_line in a simple strdup_wlen in dup_continuation_of_line
**	opti possible when buf[0] = '\n' in dup_continuation_of_line
*/

int		ft_strdup_continuation_of_line(char *buf, char **line,
		int prev_len, int len)
{
	char	*tmp;
	int		i;

	ft_strdup_start_of_line(*line, &tmp, prev_len);
	free(*line);
	if (!(*line = malloc((prev_len + len + 1) * sizeof(char))))
	{
		free(tmp);
		return (-1);
	}
	i = 0;
	while (*tmp)
		line[0][i++] = *(tmp++);
	free(tmp - i);
	while (*buf && *buf != '\n')
	{
		line[0][i++] = *buf;
		*(buf++) = -1;
	}
	line[0][i] = 0;
	if (!*buf)
		return (i);
	*buf = -1;
	return (0);
}

int		ft_strdup_line(char *buf, char **line, int prev_len)
{
	char	*s;

	while (*buf == -1)
		buf++;
	s = buf;
	while (*s && *s != '\n')
		s++;
	if (!prev_len)
		return (ft_strdup_start_of_line(buf, line, s - buf));
	return (ft_strdup_continuation_of_line(buf, line, prev_len, s - buf));
}

int		get_next_line(int fd, char **line)
{
	static char	buf[250][BUFFER_SIZE + 1] = {0};
	int			bytes_read;
	int			len;
	int			have_to_read;

	if (BUFFER_SIZE == 0 || fd < 0 || !line)
		return (-1);
	len = 0;
	buf[fd][0] = (ft_is_buf_only_minus_one(buf[fd])) ? 0 : buf[fd][0];
	have_to_read = !(buf[fd][0]);
	while (!have_to_read || (bytes_read = read(fd, buf[fd], BUFFER_SIZE)) > 0)
	{
		if (have_to_read)
			buf[fd][bytes_read] = 0;
		if ((len = ft_strdup_line(buf[fd], line, len)) == -1)
			return (-1);
		else if (!len)
			return (1);
		have_to_read = 1;
	}
	if (bytes_read == -1)
		return (-1);
	if (!len)
	{
		if (!(*line = malloc(sizeof(char))))
			return (0);
		**line = 0;
	}
	return (0);
}
