#include <stdio.h>
#include "libft.h"

int main(void)
{
    char c1 = 'A';   // Carácter dentro del rango ASCII
    char c2 = 'z';   // Carácter dentro del rango ASCII
    char c3 = '5';   // Carácter numérico dentro del rango ASCII
    char c4 = '@';   // Carácter especial dentro del rango ASCII
    char c5 = 127;   // Último carácter ASCII
    char c6 = 128;   // Fuera del rango ASCII
    char c7 = -1;    // Caracter negativo, fuera del rango ASCII

    // Pruebas con caracteres dentro y fuera del rango ASCII
    printf("ft_isascii('%c') = %d (esperado: 1)\n", c1, ft_isascii(c1)); // A
    printf("ft_isascii('%c') = %d (esperado: 1)\n", c2, ft_isascii(c2)); // z
    printf("ft_isascii('%c') = %d (esperado: 1)\n", c3, ft_isascii(c3)); // 5
    printf("ft_isascii('%c') = %d (esperado: 1)\n", c4, ft_isascii(c4)); // @
    printf("ft_isascii('%c') = %d (esperado: 1)\n", c5, ft_isascii(c5)); // 127 (DEL)
    printf("ft_isascii('%c') = %d (esperado: 0)\n", c6, ft_isascii(c6)); // 128 (fuera de ASCII)
    printf("ft_isascii('%c') = %d (esperado: 0)\n", c7, ft_isascii(c7)); // -1 (fuera de ASCII)

    return 0;
}

