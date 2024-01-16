#include "libft.h"

size_t  count_words(const char *str, char c)
{
    size_t  words_count;
    int     sep;

    words_count = 0;
    sep = 1;
    while (*str)
    {
        if (*str != c && sep != 0)
        {
            sep = 0;
            words_count++;
        }
        else if (*str == c)
            sep = 1;
        str++;
    }
    return (words_count);
}

static void     make_words(char **words, const char *str, char c, size_t words_nb)
{
    char    *ptr_c;

    while (*str && *str == c)
        str++;
    while (words_nb-- != 0)
    {
        ptr_c = ft_strchr(str, c);
        if (ptr_c != 0)
        {
            *words = ft_substr(str, 0, (ptr_c - str));
            while (*ptr_c && *ptr_c == c)
                ptr_c++;
            str = ptr_c;
        }
        else
            *words = ft_substr(str, 0, (ft_strlen(str) +1));
        words++;
    }
    *words = NULL;
}

char    **ft_split(const char *str, char c)
{
    size_t  words_nb;
    char    **words;

    if (!str)
        return (0);
    words_nb = count_words(str, c);
    words = malloc(sizeof(char **) * (words_nb + 1));
    if (!words)
        return (0);
    make_words(words, str, c, words_nb);
    return (words);
}

#include <stdio.h>

int main(void)
{
    const char *input_string = "Hello,World,This,Is,An,Example";
    char **result = ft_split(input_string, ',');

    if (result)
    {
        // Stampa le parole separate
        for (int i = 0; result[i] != NULL; i++)
        {
            printf("Word %d: %s\n", i + 1, result[i]);
        }

        // Libera la memoria allocata per le parole e l'array
        for (int i = 0; result[i] != NULL; i++)
        {
            free(result[i]);
        }
        free(result);
    }
    else
    {
        printf("Errore durante la divisione della stringa.\n");
    }

    return 0;
}
