/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clemo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 18:01:40 by clemo             #+#    #+#             */
/*   Updated: 2020/09/19 16:36:34 by clemo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strdup_start_of_line(char *buf, char **line, int len)
{
	int		i;

	if (!(*line = malloc((len + 1) * sizeof(char))))
		return (0);
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
	return (-1);
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
		return (0);
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
	return (-1);
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
	static char	buf[BUFFER_SIZE + 1] = {0};
	int			bytes_read;
	int			len;
	int			have_to_read;

	if ((fd <= 2 && fd != 0) || !line)
		return (-1);
	/* if (*buf) */
		/* free(*line); */
	len = 0;
	*buf = (ft_is_buf_only_minus_one(buf)) ? 0 : *buf;
	have_to_read = !(*buf);
	while (!have_to_read || (bytes_read = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		if (have_to_read)
			buf[bytes_read] = 0;
		if (!(len = ft_strdup_line(buf, line, len)))
			return (-1);
		if (len == -1)
			return (1);
		have_to_read = 1;
	}
	if (bytes_read == -1)
		return (-1);
	return (0);
}
