/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 12:58:55 by schahid           #+#    #+#             */
/*   Updated: 2021/11/29 13:00:26 by schahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

char					*get_next_line(int fd);

size_t					ft_strlen(char *str);

char					*ft_strchr(char *s, int c);

char					*ft_strjoin(char *s1, char *s2);

char					*first_line(char *s_buff);

char					*next_line(char *s_buff);

char					*ft_read(int fd, char *s_buff);

char					*get_next_line(int fd);

#endif
