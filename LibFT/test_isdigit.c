#include <stdio.h>
#include "libft.h"

int main(void)
{
    char c1 = '0';    // Primer dígito
    char c2 = '5';    // Un dígito común
    char c3 = '9';    // Último dígito
    char c4 = 'A';    // Letra mayúscula (no es dígito)
    char c5 = 'z';    // Letra minúscula (no es dígito)
    char c6 = ' ';    // Espacio (no es dígito)
    char c7 = '\n';   // Salto de línea (no es dígito)
    char c8 = -1;     // Carácter fuera del rango de dígitos

    // Pruebas con caracteres de dígitos y no dígitos
    printf("ft_isdigit('%c') = %d (esperado: 1)\n", c1, ft_isdigit(c1)); // '0'
    printf("ft_isdigit('%c') = %d (esperado: 1)\n", c2, ft_isdigit(c2)); // '5'
    printf("ft_isdigit('%c') = %d (esperado: 1)\n", c3, ft_isdigit(c3)); // '9'
    printf("ft_isdigit('%c') = %d (esperado: 0)\n", c4, ft_isdigit(c4)); // 'A'
    printf("ft_isdigit('%c') = %d (esperado: 0)\n", c5, ft_isdigit(c5)); // 'z'
    printf("ft_isdigit('%c') = %d (esperado: 0)\n", c6, ft_isdigit(c6)); // Espacio
    printf("ft_isdigit('%c') = %d (esperado: 0)\n", c7, ft_isdigit(c7)); // Salto de línea
    printf("ft_isdigit('%c') = %d (esperado: 0)\n", c8, ft_isdigit(c8)); // Carácter negativo fuera del rango

    return 0;
}
