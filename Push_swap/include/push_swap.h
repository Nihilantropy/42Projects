/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:56:17 by crea              #+#    #+#             */
/*   Updated: 2024/04/17 13:21:49 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include "messages.h"
# include "../libft/include/libft.h"
# include "../ft_printf/include/ft_printf.h"

/* defining double circular struct list */
typedef struct s_stack
{
	int				data;
	int				index;
	int				push_cost;
	bool			is_above_median;
	bool			is_cheapest;
	struct s_stack	*target_node;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

/* init stack functions to set up and free the stack */
void	init_stack(t_stack **a, char **matrix);
void	create_node(t_stack **stack, int nbr);

/* main utils */
char	**build_matrix(int argc, char **argv);
void	free_matrix(char **matrix);

/* checks */
int		check_format(char **matrix);
int		check_double(t_stack *a, int nbr);
bool	check_if_sorted(t_stack *a);

/* utils 1 */
int		stack_size(t_stack *a);
void	free_stack(t_stack **head);

/* utils 2 */
void	print_list(t_stack *a);
void	print_nodes_addr(t_stack *stack);
void	print_target_node(t_stack *stack);
void	print_push_cost(t_stack *stack);
void	print_node_median(t_stack *stack);

/* tiny sort with stack == 3 */
void	tiny_sort(t_stack **a);

/* sort stack */
void	choose_sort(t_stack **a, t_stack **b);
void	sort_stacks(t_stack **a, t_stack **b);
void	init_stack_a(t_stack *a, t_stack *b);
void	init_stack_b(t_stack *a, t_stack *b);

/* sort stack utils 1 */
t_stack	*find_min(t_stack *a);
t_stack	*find_max(t_stack *a);
void	set_target_a(t_stack *a, t_stack *b);
void	set_target_b(t_stack *a, t_stack *b);
void	find_target_cost(t_stack *a, t_stack *b);

/* sort stack utils 2 */
void	set_cheapest_node(t_stack *stack);
void	current_index(t_stack *stack);
void	push_a_to_b(t_stack **a, t_stack **b);
void	push_b_to_a(t_stack **a, t_stack **b);

/* sort stack utils 3 */
t_stack	*get_cheapest_node(t_stack *stack);
void	rotate_ab(t_stack **a, t_stack **b,
			t_stack *cheapest_node);
void	rev_rotate_ab(t_stack **a, t_stack **b,
			t_stack *cheapest_node);
void	min_on_top(t_stack **a);
void	prep_for_push(t_stack **stack,
			t_stack *cheapest_node,
			char stack_name);

/* rules for stack a */
void	sa(t_stack **a, bool write);
void	pa(t_stack **a, t_stack **b, bool write);
void	ra(t_stack **a, bool write);
void	rra(t_stack **a, bool write);

/* rules for stack b */
void	sb(t_stack **b, bool write);
void	pb(t_stack **a, t_stack **b, bool write);
void	rb(t_stack **b, bool write);
void	rrb(t_stack **a, bool write);

/* rules for both stacks a and b */
void	ss(t_stack **a, t_stack **b, bool write);
void	rr(t_stack **a, t_stack **b, bool write);
void	rrr(t_stack **a, t_stack **b, bool write);

#endif