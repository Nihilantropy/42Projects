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
	long			data;
	long			index;
	long			push_cost;
	bool			isAboveMedian;
	bool			isCheapest;
	struct s_stack	*target_node;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

/* init stack functions to set up and free the stack */
void	init_stack(t_stack **a, char **matrix);
void	create_node(t_stack **stack, int nbr);

/* main utils */
char	**build_matrix(int argc, char **argv);
int		check_format(char **matrix);
void	check_sort(t_stack **a, t_stack **b);
bool	check_if_sorted(t_stack *a);
void	print_list(t_stack *a);

/* init stack utils */
int		check_double(t_stack *a, int nbr);
void	free_stack(t_stack **head);

/* tiny sort with stack == 3 */
void	tiny_sort(t_stack **a);

/* sort stack */
void	sort_stacks(t_stack **a, t_stack **b);
void	count_moves(t_stack *a, t_stack *b);

/* sort stack utils */
t_stack	*find_last_node(t_stack *a);
t_stack	*return_cheapest(t_stack *a);
t_stack	*find_min(t_stack *a);
t_stack	*find_max(t_stack *a);
int				stack_size(t_stack *a);

/* sort stack utils 2 */
void	rotate_both(t_stack **a,
					t_stack **b,
					t_stack *cheapest_node);
void	prep_for_push(t_stack **stack,
						t_stack **top_node,
						char stack_name);

/* algorithm */
void	init_nodes_a(t_stack *a, t_stack *b);
void	init_nodes_b(t_stack *a, t_stack *b);

/* rules for stack a */
void	sa(t_stack **a, bool write);
void	pa(t_stack **a, t_stack **b, bool write);
void	ra(t_stack **a, bool write);
void	rra(t_stack **a, bool write);

/* rules for stack b */
void	sb(t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	rb(t_stack **b);
void	rrb(t_stack **a);

/* rules for both stacks a and b */
void	ss(t_stack **a, t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rrr(t_stack **a, t_stack **b);

#endif