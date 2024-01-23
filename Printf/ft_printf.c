#include "libftprintf.h"
#include <stdio.h>

#include <stdarg.h>
#include <unistd.h>

int ft_printf(const char *s, ...)
{
    va_list args;
    va_start(args, s);

    void *ptr;
    int count = 0;  // Contatore di caratteri stampati

    while (*s != '\0')
    {
        if (*s == '%' && *(s + 1) != '\0')
        {
            s++;  // Passa al carattere successivo dopo '%'
            if (*s == 'd') 
            {
                int(*ptr) = va_arg(args, int);
                count += ft_putnbr_fd((int)*ptr, 1);
            } else if (*s == 'c') 
            {
                char ch = va_arg(args, int);  // I caratteri si promuovono a int
                count += write(1, &ch, sizeof(char));
            } else if (*s == 's')

        } else {
            // Stampa caratteri ordinari
            count += write(1, s, 1);
        }

        s++;  // Passa al prossimo carattere nella stringa di formato
    }

    va_end(args);

    return count;  // Restituisce il numero totale di caratteri stampati
}

int main() {
    ft_printf("Hello, %c! My favorite number is %d.\n", 'a', 4);

    return 0;
}
