#include <stdio.h>
#include "libft.h"

int main(void)
{
    char c1 = 'A';    // Carácter imprimible
    char c2 = 'z';    // Carácter imprimible
    char c3 = ' ';    // Espacio (imprimible)
    char c4 = '@';    // Carácter especial imprimible
    char c5 = 31;     // Carácter no imprimible (ASCII 31)
    char c6 = 127;    // Carácter no imprimible (DEL)
    char c7 = -1;     // Valor fuera del rango ASCII

    // Pruebas con caracteres imprimibles y no imprimibles
    printf("ft_isprint('%c') = %d (esperado: 1)\n", c1, ft_isprint(c1)); // 'A'
    printf("ft_isprint('%c') = %d (esperado: 1)\n", c2, ft_isprint(c2)); // 'z'
    printf("ft_isprint('%c') = %d (esperado: 1)\n", c3, ft_isprint(c3)); // Espacio
    printf("ft_isprint('%c') = %d (esperado: 1)\n", c4, ft_isprint(c4)); // '@'
    printf("ft_isprint('%c') = %d (esperado: 0)\n", c5, ft_isprint(c5)); // 31 (no imprimible)
    printf("ft_isprint('%c') = %d (esperado: 0)\n", c6, ft_isprint(c6)); // 127 (DEL, no imprimible)
    printf("ft_isprint('%c') = %d (esperado: 0)\n", c7, ft_isprint(c7)); // -1 (fuera de ASCII)

    return 0;
}
