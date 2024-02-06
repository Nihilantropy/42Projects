/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:05:32 by crea              #+#    #+#             */
/*   Updated: 2024/02/06 14:57:53 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 4
#endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct  s_list
{
    char            *str_buf;
    struct s_list   *next;
}           t_list; // t_list struct definition to make simpler moving from node to node

int     found_newline(t_list *list); // return 1 if new line is found, first in the buffer read, then in the next node and so on, until the '\0'
t_list  *find_last_node(t_list *list); // go to the last node of the existing list
char    *get_line(t_list *list); // extract the \n line
void    copy_str(t_list *list, char *str); // copy the string read into the buffer
int     len_to_newline(t_list *list); // how far is the \n from the start 0 of the line
void    polish_list(t_list **list); // polish the list for the next call
void	append(t_list **list, char *buf); // append a new node at the end of the list
char    *get_next_line(int fd); // take a file descriptor and return the first \n terminated string
void    dealloc(t_list **list, t_list *clean_node, char *buf); // clean all list and make the list start with the remained (if there is) buffer read.
void    create_list(t_list **list, int fd); // initializing the list

#endif