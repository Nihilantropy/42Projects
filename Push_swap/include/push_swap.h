#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "messages.h"
# include "../libft/include/libft.h"
# include "../ft_printf/include/ft_printf.h"

/* defining double circular struct list */
typedef struct s_linked_list
{
	int						data;
	int						biggest;
	int						cheapest;
	struct s_linked_list	*prev;
	struct s_linked_list	*next;
}	t_linked_list;

/* main functions to set up and free the stack */
char	**build_matrix(int argc, char **argv);
int		check_format(char **matrix);
void	init_stack(t_linked_list **a, char **matrix);
int		check_double(t_linked_list *a, int nbr);
void	push(t_linked_list **a, int nbr);
void	free_stack(t_linked_list *a);

/* sort stack utils */
int		stack_size(t_linked_list **a);

void	print_list(t_linked_list **a);

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

void	pa(t_linked_list **a, t_linked_list **b);


//void	sa(t_struct_list *list);

#endif