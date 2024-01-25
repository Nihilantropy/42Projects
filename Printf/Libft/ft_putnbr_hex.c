#include "libft.h"

int ft_putnbr_hex(int n, char c)
{
    int         hex_digits[100];
    int         i;
    int         count;
    const char  *hex_chars;

    i = 0;
    count = 0;
    if (n < 0)
    {
        count += ft_putchar('-');
        n = -n;
    }
    while (n > 0)
    {
        hex_digits[i++] = n % 16;
        n /= 16;
    }
    hex_chars = (c == 'X') ? "0123456789ABCDEF" : "0123456789abcdef";
    while (i-- > 0)
        count += ft_putchar(hex_chars[hex_digits[i]]);
    return (count);
}
