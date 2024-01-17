#include "libft.h"
#include <stdlib.h>

void    lstadd_front(t_list **lst, t_list *new)
{
    if (!lst || !new)
        return ;
    // Update the 'next' pointer of the new node to point to the current head of the list
    new -> next;

    next = *lst;
    // Update the head of the list to be the new node
    *lst = new;
}