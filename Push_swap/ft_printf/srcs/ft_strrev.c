#include "../include/ft_printf.h"

void    ft_strrev(char *str)
{
	char	c;
	int		i;
	int		n;

	if (!str)
		return ;
	i = 0;
	n = ft_strlen(str);
	while (i < n / 2)
	{
		c = str[n - i - 1];
		str[n - i - 1] = str[i];
		str[i] = c;
		i++;
	}
    ft_putstr(str);
}