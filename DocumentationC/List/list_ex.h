#ifndef LIST_EX_H
# define LIST_EX_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/include/libft.h"
# include "../ft_printf/include/ft_printf.h"

/* defining linked list struct */
typedef struct s_struct_list
{
	int				data;
	struct s_struct_list	*prev;
	struct s_struct_list	*next;
}	t_struct_list;


#endif