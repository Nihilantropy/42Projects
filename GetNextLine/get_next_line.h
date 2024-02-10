/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 19:59:36 by crea              #+#    #+#             */
/*   Updated: 2024/02/10 02:35:34 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_list {
	char    *data;
	struct  s_list  *next;
}           t_list;

char	*get_next_line(int fd);
void	polish_list(t_list **list);
void	clean_list(t_list **list, t_list *new_head, char *buffer);
int		ft_strlen(char *str);
void	create_buffer(t_list **list, int fd);
void	create_new_node(t_list **list, char *buffer);
t_list	*find_last_node(t_list **list);
int		found_newline(t_list *list);
char	*extract_line(t_list *list);
char	*ft_strcpy(char *s1, char *s2);
void	cpy_nodes(char *str, t_list *list);
int		count_to_newline(t_list *list);

#endif
