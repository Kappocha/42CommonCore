#include <fcntl.h>
#include <unistd.h>
#include "libft.h"

int main(void)
{
    char c1;
    char c2;
    char c3;

    c1 = 'A';
    c2 = '\n';
    c3 = 'Z';

    ft_putchar_fd(c1, 1); // Imprime 'A'
    ft_putchar_fd(c2, 1); // Salto de línea
    ft_putchar_fd(c3, 1); // Imprime 'Z'
    ft_putchar_fd('\n', 1); // Salto de línea final

    return 0;
}
