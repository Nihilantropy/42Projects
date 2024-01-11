#include "libft.h"

int     ft_atoi(const char *str)
{
    int nbr;
    int sign;
    int i;

    nbr = 0;
    sign = 1;
    i = 0;
    while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' ||
			str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
        i++;
    if (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            sign *= -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
        nbr = (nbr * 10) + str[i++] - '0';
    return (nbr * sign);
}