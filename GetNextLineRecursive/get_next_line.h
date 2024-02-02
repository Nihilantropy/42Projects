/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:18:45 by crea              #+#    #+#             */
/*   Updated: 2024/02/01 21:10:04 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2);
int     find_n(char *buffer);
void	ft_strcpy(char *dest, char *src);
char	*str_ret(int n, char *buffer);
char	*ret(int n, char *buffer, int fd);
char    *get_next_line(int fd);

#endif
