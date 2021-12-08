/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahid <schahid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 10:49:25 by schahid           #+#    #+#             */
/*   Updated: 2021/11/29 12:47:33 by schahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_read(int fd, char *s_buff)
{
	char	*buffer;
	int		b;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	b = 1;
	while (!ft_strchr(s_buff, '\n') && b)
	{
		b = read(fd, buffer, BUFFER_SIZE);
		if (b == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[b] = '\0';
		s_buff = ft_strjoin(s_buff, buffer);
	}
	free(buffer);
	return (s_buff);
}

char	*get_next_line(int fd)
{
	static char	*s_buff;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	s_buff = ft_read(fd, s_buff);
	if (!s_buff)
		return (NULL);
	line = first_line(s_buff);
	s_buff = next_line(s_buff);
	return (line);
}
