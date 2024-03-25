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
typedef struct s_linked_list
{
	long					data;
	long					index;
	long					push_cost;
	bool					above_median;
	bool					cheapest;
	struct s_linked_list	*target_node;
	struct s_linked_list	*prev;
	struct s_linked_list	*next;
}	t_linked_list;

/* init stack functions to set up and free the stack */
void	init_stack(t_linked_list **a, char **matrix);
void	create_node(t_linked_list **a, int nbr);

/* main utils */
char	**build_matrix(int argc, char **argv);
int		check_format(char **matrix);
void	check_sort(t_linked_list **a, t_linked_list **b);
bool	check_if_sorted(t_linked_list *a);
void	print_list(t_linked_list *a);

/* init stack utils */
int		check_double(t_linked_list *a, int nbr);
void	free_stack(t_linked_list **head);

/* tiny sort with stack == 3 */
void	tiny_sort(t_linked_list **a);

/* sort stack */
void	sort_stacks(t_linked_list **a, t_linked_list **b);
void	count_moves(t_linked_list *a, t_linked_list *b);

/* sort stack utils */
t_linked_list	*find_last_node(t_linked_list *a);
t_linked_list	*return_cheapest(t_linked_list *a);
t_linked_list	*find_min(t_linked_list *a);
t_linked_list	*find_max(t_linked_list *a);
int				stack_size(t_linked_list *a);

/* sort stack utils 2 */
void	rotate_both(t_linked_list **a,
					t_linked_list **b,
					t_linked_list *cheapest_node);
void	prep_for_push(t_linked_list **stack,
						t_linked_list **top_node,
						char stack_name);

/* algorithm */
void	init_nodes_a(t_linked_list *a, t_linked_list *b);
void	init_nodes_b(t_linked_list *a, t_linked_list *b);

/* rules for stack a */
void	sa(t_linked_list **a);
void	pa(t_linked_list **a, t_linked_list **b);
void	ra(t_linked_list **a);
void	rra(t_linked_list **a);

/* rules for stack b */
void	sb(t_linked_list **b);
void	pb(t_linked_list **a, t_linked_list **b);
void	rb(t_linked_list **b);
void	rrb(t_linked_list **a);

/* rules for both stacks a and b */
void	ss(t_linked_list **a, t_linked_list **b);
void	rr(t_linked_list **a, t_linked_list **b);
void	rrr(t_linked_list **a, t_linked_list **b);

/* print error / success msg */
void	ft_print_error(char *error);
void	ft_print_success(char *success);

#endif