# include "../include/push_swap.h"

char **build_matrix(int argc, char **argv)
{
    char **matrix;
    int i;

    matrix = malloc(sizeof(char **) * argc);
    if (!matrix)
        return (0);
    i = 0;
    while (i < argc)
    {
        matrix[i] = argv[i];
        i++;
    }
    return (matrix); 
}

int main(int argc, char **argv)
{
    char **matrix;

    matrix = NULL;
    if (argc == 1 || (argc == 2 && !argv[1][0]))
        return(ft_printf(ERROR_ARG_NBR));
    else if (argc == 2)
        matrix = ft_split(argv[1], ' ');
    else if (argc > 2)
        matrix = build_matrix(argc, argv);
    for (int i = 1; i < 8; i++)
        ft_printf("%s\n", matrix[i]);
    free(matrix);
}