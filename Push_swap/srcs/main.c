# include "../include/push_swap.h"

int main(int argc, char **argv)
{
    t_linked_list *a;
    t_linked_list *b;

    a = NULL;
    b = NULL;
    char **matrix;

    matrix = NULL;
    if (argc == 1 || (argc == 2 && !argv[1][0]))
        return(ft_printf(ERROR_ARG_NBR));
    else if (argc == 2)
    {
        matrix = ft_split(argv[1], ' ');
        init_stack(&a, matrix);
    }
    else if (argc > 2)
    {
        matrix = build_matrix(argc, (argv + 1));
        init_stack(&a, matrix);
    }
    free(matrix);
    while (a) {
        ft_printf("%d\n", a->data);
        a = a->next;
    }
    return (0);
}