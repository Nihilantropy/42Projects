#include "../include/so_long.h"

int check_map_ext(char *map_file)
{
    int len;
    int wrong;

    wrong = 0;
    len = ft_strlen(map_file) - 1;
    if (map_file[len] != 'r')
        wrong = 1;
    len--;
    if (map_file[len] != 'e')
        wrong = 1;
    len--;
    if (map_file[len] != 'b')
        wrong = 1;
    len--;
    if (map_file[len] != '.')
        wrong = 1;
    if (wrong == 1)
    {
        ft_printf(ERROR_MAP_EXT);
        return (0);
    }
    else
        return (ft_printf(CORRECT_MAP_EXT));
}