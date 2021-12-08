/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahid <schahid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 13:48:34 by schahid           #+#    #+#             */
/*   Updated: 2021/12/01 16:07:17 by schahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	size_t	i ;

	i = 0 ;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	if (s1)
		while (s1[++i] != '\0')
			str[i] = s1[i];
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (str);
}

char	*first_line(char *s_buff)
{
	char	*str;
	int		i;

	i = 0;
	if (!s_buff[i])
		return (NULL);
	while (s_buff[i] && s_buff[i] != '\n')
		i++ ;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (s_buff[i] && s_buff[i] != '\n')
	{
		str[i] = s_buff[i];
		i++ ;
	}
	if (s_buff[i] == '\n')
	{
		str[i] = s_buff[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*next_line(char *s_buff)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (s_buff[i] && s_buff[i] != '\n')
		i++ ;
	if (!s_buff[i])
	{
		free(s_buff);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(s_buff) - (i + 1)) + 1);
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (s_buff[i])
		str[j++] = s_buff[i++];
	str[j] = '\0';
	free(s_buff);
	return (str);
}
