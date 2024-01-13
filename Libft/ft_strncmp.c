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

int     ft_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t i;

    i = 0;
    if (n == 0)
        return (0);
    while ((s1[i] || s2[i]) && (i < n -1) && s1[i] == s2[i])
        i++;
    return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}