#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "messages.h"
# include "../libft/include/libft.h"
# include "../ft_printf/include/ft_printf.h"

/* defining double circular struct list */
typedef struct s_linked_list
{
	int				data;
	struct s_linked_list	*prev;
	struct s_linked_list	*next;
}	t_linked_list;

char	**build_matrix(int argc, char **argv);
void	init_stack(t_linked_list **a, char **matrix);
int		check_double(t_linked_list *a, int nbr);

/* rules */

//void	sa(t_struct_list *list);

#endif