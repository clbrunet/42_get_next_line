/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 15:31:09 by clbrunet          #+#    #+#             */
/*   Updated: 2020/11/20 06:03:55 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strcpy(char *dst, const char *src)
{
	const char	*dst_bp;

	if (!dst || !src)
		return (0);
	dst_bp = dst;
	while (*src)
	{
		*dst = *src;
		dst++;
		src++;
	}
	*dst = 0;
	return ((char *)dst_bp);
}

int		failed_malloc(void *to_free)
{
	free(to_free);
	return (-1);
}
