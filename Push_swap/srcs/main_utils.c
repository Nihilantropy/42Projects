/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:50:07 by crea              #+#    #+#             */
/*   Updated: 2024/03/19 19:20:39 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/push_swap.h"

char **build_matrix(int argc, char **argv)
{
	char **matrix;
	int i;

	matrix = (char **)malloc(sizeof(char *) * argc);
	if (!matrix)
		return (NULL);
	i = 0;
	while (i < argc)
	{
		matrix[i] = argv[i];
		i++;
	}
	matrix[argc] = NULL;
	return (matrix); 
}

int	check_format(char **matrix)
{
	int x;
	int y;

	y = 0;
	while (matrix[y])
	{
		x = 0;
		while (matrix[y][x])
		{
			if (!ft_isdigit(matrix[y][x]))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

void print_list(t_linked_list **head)
{
	t_linked_list *current;
	
	current = *head;
	while (current)
	{
		ft_printf("%d ", current->data);
		current = current->next;
		if (current == *head)
			break ;
	}
}