#include <stdio.h>
#include <string.h>  // Para comparar con la función estándar de memcmp
#include "libft.h"

int main(void)
{
    // Datos de prueba
    const char str1[] = "Hola, mundo!";
    const char str2[] = "Hola, mundo!";
    const char str3[] = "Hola, Mundo!";
    const char str4[] = "Hola, universo!";
    const char str5[] = "Hola";

    // Usamos ft_memcmp
    int result1 = ft_memcmp(str1, str2, sizeof(str1)); // Debería ser 0 (mismas cadenas)
    int result2 = ft_memcmp(str1, str3, sizeof(str1)); // Debería ser negativo (diferente en 'm' y 'M')
    int result3 = ft_memcmp(str1, str4, sizeof(str1)); // Debería ser negativo (diferente a partir de 'u')
    int result4 = ft_memcmp(str1, str5, sizeof(str5)); // Debería ser positivo (str1 es más largo)

    // Comparar con la función estándar memcmp
    int std_result1 = memcmp(str1, str2, sizeof(str1));
    int std_result2 = memcmp(str1, str3, sizeof(str1));
    int std_result3 = memcmp(str1, str4, sizeof(str1));
    int std_result4 = memcmp(str1, str5, sizeof(str5));

    // Imprimimos los resultados
    printf("ft_memcmp(str1, str2) = %d (esperado: 0)\n", result1);
    printf("ft_memcmp(str1, str3) = %d (esperado: negativo)\n", result2);
    printf("ft_memcmp(str1, str4) = %d (esperado: negativo)\n", result3);
    printf("ft_memcmp(str1, str5) = %d (esperado: positivo)\n", result4);

    // Comprobamos que las implementaciones son consistentes
    printf("\nComparando con la versión estándar:\n");
    printf("memcmp(str1, str2) = %d (esperado: 0)\n", std_result1);
    printf("memcmp(str1, str3) = %d (esperado: negativo)\n", std_result2);
    printf("memcmp(str1, str4) = %d (esperado: negativo)\n", std_result3);
    printf("memcmp(str1, str5) = %d (esperado: positivo)\n", std_result4);

    return 0;
}
