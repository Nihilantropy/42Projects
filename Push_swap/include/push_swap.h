#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "messages.h"
# include "../libft/include/libft.h"
# include "../ft_printf/include/ft_printf.h"

/* defining double circular struct list */
typedef struct s_linked_list
{
	int				data;
	struct s_struct_list	*prev;
	struct s_struct_list	*next;
}	t_linked_list;

/* rules */

//void	sa(t_struct_list *list);

#endif