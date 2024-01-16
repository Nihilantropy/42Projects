#include "libft.h"
#include <stdlib.h>

static  size_t  getdigits(int n)
{
	size_t	digits;

	digits = 1;
	if (n < 0)
		digits++;
	while (n /= 10)
		digits++;
	return (digits);
}

char	*ft_itoa(int n)
{
	char		*digit_str;
	size_t		digits;
	long int	nb;

	nb = n;
	digits = getdigits(nb);
	if (nb < 0)
		nb *= -1;
	digit_str = (char *)malloc((digits + 1) * sizeof(char));
	if (!digit_str)
		return (0);
	digit_str[digits] = '\0';
	while (digits-- != 0)
	{
		digit_str[digits] = nb % 10 + 48;
		nb = nb / 10;
	}
	if (n < 0)
		digit_str[0] = '-';
	return (digit_str);
}