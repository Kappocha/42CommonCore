#include "libft.h"
#include <unistd.h>

int main(void)
{
    char *s1 = "Hola, mundo!";
    char *s2 = "";
    char *s3 = "Cadena larga con varios caracteres: 1234567890!@#";
    char *s4 = NULL;

    ft_putstr_fd(s1, 1);
    write(1, "\n", 1);

    ft_putstr_fd(s2, 1);
    write(1, "\n", 1);

    ft_putstr_fd(s3, 1);
    write(1, "\n", 1);

    ft_putstr_fd(s4, 1); // debería no hacer nada si se controla correctamente

    return 0;
}
