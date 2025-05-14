#include <stdio.h>
#include "libft.h"

int main(void)
{
    char c1 = 'A';
    char c2 = 'z';
    char c3 = '5';
    char c4 = '@';  // Carácter no alfanumérico
    char c5 = ' ';  // Espacio
    char c6 = '\n'; // Salto de línea

    // Pruebas con caracteres alfanuméricos y no alfanuméricos
    printf("ft_isalnum('%c') = %d (esperado: 1)\n", c1, ft_isalnum(c1)); // A
    printf("ft_isalnum('%c') = %d (esperado: 1)\n", c2, ft_isalnum(c2)); // z
    printf("ft_isalnum('%c') = %d (esperado: 1)\n", c3, ft_isalnum(c3)); // 5
    printf("ft_isalnum('%c') = %d (esperado: 0)\n", c4, ft_isalnum(c4)); // @
    printf("ft_isalnum('%c') = %d (esperado: 0)\n", c5, ft_isalnum(c5)); // Espacio
    printf("ft_isalnum('%c') = %d (esperado: 0)\n", c6, ft_isalnum(c6)); // Salto de línea

    return 0;
}
