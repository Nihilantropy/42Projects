/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:50:07 by crea              #+#    #+#             */
/*   Updated: 2024/03/23 11:52:40 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	check_sort(t_linked_list **a, t_linked_list **b)
{
	if (!check_if_sorted(*a))
	{
		if (stack_size(*a) == 2)
			sa(a);
		else if (stack_size(*a) == 3)
			tiny_sort(a);
		else
			sort_stacks(a, b);
	}
}

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

void print_list(t_linked_list *head)
{
	if (!head)
	{
		ft_printf("(null)");
		return ;
	}
	t_linked_list *current;
	
	current = head;
	while (1)
	{
		ft_printf("%d ", current->data);
		current = current->next;
		if (current == head)
			break ;
	}
	ft_putnl();
}

