#include "../include/push_swap.h"

char *concat_args(int argc, char **argv)
{
    char *args_str;
    char *temp;
    int i;

    args_str = NULL;
    i = 1;
    while (i < argc)
    {
        if (args_str == NULL)
            args_str = ft_strdup(argv[i]);
        else 
        {
            temp = args_str;
            args_str = ft_strjoin(args_str, " ");
            free(temp);
            temp = args_str;
            args_str = ft_strjoin(args_str, argv[i]);
            free(temp);
        }
        i++;
    }
    return args_str;
}

int main(int argc, char **argv)
{
    char **args;
    char *input_str;
    int new_argc;
    int i;

    if (argc == 1)
        return (ft_printf("Errore: nessun argomento fornito.\n"));
    else if (argc == 2)
        input_str = argv[1];
    else
        input_str = concat_args(argc, argv);
    args = ft_split(input_str, ' ');
    new_argc = 0;
    while (args[new_argc] != NULL)
        new_argc++;

    // Stampa i nuovi argomenti per debug
    i = 0;
    while (i < new_argc)
    {
        ft_printf("%s\n", args[i]);
        i++;
    }

    // Libera la memoria allocata
    if (argc > 2) {
        free(input_str); // Liberiamo solo se abbiamo effettivamente allocato una nuova stringa
    }
    i = 0;
    while (i < new_argc) {
        free(args[i]);
        i++;
    }
    free(args);

    return 0;
}