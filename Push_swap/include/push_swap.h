#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/include/libft.h"
# include "../ft_printf/include/ft_printf.h"

/* defining double circular struct list */
typedef struct dcs_list
{
	int				data;
	struct dcs_list	*next;
	struct dcs_list	*prev;
}			dct_list;

/* rules */

//void	sa(dct_list *list);

#endif