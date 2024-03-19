# include "../include/push_swap.h"

int check_double(t_linked_list *a, int nbr)
{
    while (a != NULL)
    {
        if (a->data == nbr)
            return (1);
        a = a->next;
    }
    return (0);
}

void push(t_linked_list **a, int nbr)
{
    t_linked_list *new_node;

    new_node = malloc(sizeof(t_linked_list));
    if (!new_node)
        exit(1);

    new_node->data = nbr;
    new_node->next = *a;
    new_node->prev = NULL;
    if (*a != NULL)
        (*a)->prev = new_node;
    *a = new_node;
}

void    init_stack(t_linked_list **a, char **matrix)
{
    long nbr;

    while (*matrix)
    {
        nbr = ft_atol(*matrix);
        if (nbr > INT_MAX || nbr < INT_MIN)
            exit(1);
        if (!check_double(*a, (int)nbr))
            push(a, (int)nbr);
        matrix++;
    }
}

char **build_matrix(int argc, char **argv)
{
    char **matrix;
    int i;

    matrix = (char **)malloc(sizeof(char *) * argc);
    if (!matrix)
        return (NULL);
    i = 0;
    while (i < argc)
    {
        matrix[i] = argv[i];
        i++;
    }
    matrix[argc] = NULL;
    return (matrix); 
}