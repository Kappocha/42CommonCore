#include <stdio.h>
#include "libft.h"

int main(void)
{
    char c1 = 'A';  // Letra mayúscula
    char c2 = 'z';  // Letra minúscula
    char c3 = '5';  // Dígito
    char c4 = '@';  // Carácter especial
    char c5 = ' ';  // Espacio
    char c6 = '\n'; // Salto de línea
    char c7 = 127;  // Carácter de control (DEL)

    // Pruebas con caracteres alfabéticos y no alfabéticos
    printf("ft_isalpha('%c') = %d (esperado: 1)\n", c1, ft_isalpha(c1)); // A
    printf("ft_isalpha('%c') = %d (esperado: 1)\n", c2, ft_isalpha(c2)); // z
    printf("ft_isalpha('%c') = %d (esperado: 0)\n", c3, ft_isalpha(c3)); // 5
    printf("ft_isalpha('%c') = %d (esperado: 0)\n", c4, ft_isalpha(c4)); // @
    printf("ft_isalpha('%c') = %d (esperado: 0)\n", c5, ft_isalpha(c5)); // Espacio
    printf("ft_isalpha('%c') = %d (esperado: 0)\n", c6, ft_isalpha(c6)); // Salto de línea
    printf("ft_isalpha('%c') = %d (esperado: 0)\n", c7, ft_isalpha(c7)); // Carácter de control

    // Prueba con caracteres extendidos (fuera del rango estándar ASCII)
    printf("ft_isalpha('%c') = %d (esperado: 0 o 1, depende de la implementación)\n", 128); // Caracter extendido

    return 0;
}
