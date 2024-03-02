#include "../include/so_long.h"

int check_map_ext(char *map_file)
{
    int len;
    t_bool wrong;

    wrong = 0;
    len = ft_strlen(map_file) - 1;
    if (map_file[len] != 'r' && map_file[len - 1] != 'e' && map_file[len - 2] != 'b'
        && map_file[len - 3] != '.')
        wrong = 1;
    if (wrong == 1)
    {
        ft_printf(ERROR_MAP_EXT);
        return (0);
    }
    else
        return (ft_printf(CORRECT_MAP_EXT));
}