#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/include/libft.h"


/* structure def for list a */
typedef struct sa_list
{
	int				data;
	struct sa_list	*next;
}			a_list;

/* structure def for list b */
typedef struct sb_list
{
	int				data;
	struct sb_list	*next;
}			b_list;

/* rules */

//void	sa(a_list *list);

#endif