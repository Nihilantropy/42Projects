#include "../include/so_long.h"

int check_map_ext(char *map_file)
{
    int len;

    len = ft_strlen(map_file) - 1;
    if (map_file[len] == 'r' && map_file[len - 1] == 'e' && map_file[len - 2] == 'b'
        && map_file[len - 3] == '.')
        return (ft_printf(CORRECT_MAP_EXT));
    else
    {
        ft_printf(ERROR_MAP_EXT);
        return (0);
    }
}