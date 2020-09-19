/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clemo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 18:02:20 by clemo             #+#    #+#             */
/*   Updated: 2020/09/18 18:02:20 by clemo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int		ft_is_buf_only_minus_one(char *buf);
int		ft_strdup_line(char *buf, char **line, int len);
int		ft_strdup_start_of_line(char *buf, char **line, int len);
int		ft_strdup_continuation_of_line(char *buf, char **line,
		int prev_len, int len);
int		ft_strdup_line(char *buf, char **line, int len);
int		get_next_line(int fd, char **line);

#endif
