/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clemo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 18:01:40 by clemo             #+#    #+#             */
/*   Updated: 2020/09/18 22:36:36 by clemo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strcpy_line(char	*buf, char **line, int len)
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

int		ft_strcat_line(char	*buf, char **line, int prev_len, int len)
{
	char	*tmp;
	int		i;

	ft_strcpy_line(*line, &tmp, prev_len);
	free(*line);
	if (!(*line = malloc((prev_len + len + 1) * sizeof(char))))
		return (0);
	i = 0;
	while (*tmp)
		line[0][i++] = *(tmp++);
	tmp -= i;
	free(tmp);
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

int		ft_strdup_line(char *buf, char **line, int len)
{
	char	*s;

	while (*buf == -1)
		buf++;
	s = buf;
	while (*s && *s != '\n')
		s++;
	if (!len)
		return (ft_strcpy_line(buf, line, s - buf));
	else
		return (ft_strcat_line(buf, line, len, s - buf));
}

int		is_buf_minus_one(char *buf)
{
	while (*buf)
	{
		if (*buf != -1)
			return (0);
		buf++;
	}
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char	buf[BUFFER_SIZE + 1] = {0};
	int			bytes_read;
	int			len;
	int			just_read;

	if ((fd <= 2 && fd != 0) || !line)
		return (-1);
	len = 0;
	if (is_buf_minus_one(buf))
		*buf = 0;
	if (*buf)
		just_read = 0;
	else
		just_read = 1;
	while (*buf || (bytes_read = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		if (just_read)
			buf[bytes_read] = 0;
		if (!(len = ft_strdup_line(buf, line, len)))
			return (-1);
		else if (len == -1)
			return (1);
		*buf = 0;
		just_read = 1;
	}
	if (bytes_read == -1)
		return (-1);
	return (0);
}
