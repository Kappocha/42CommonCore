#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int main(void)
{
    int num1 = 12345;   // Número positivo
    int num2 = -9876;   // Número negativo
    int num3 = 0;       // Caso del número cero
    int num4 = 2147483647; // Valor máximo de un int (INT_MAX)
    int num5 = -2147483648; // Valor mínimo de un int (INT_MIN)

    // Pruebas con varios números
    char *str1 = ft_itoa(num1);
    char *str2 = ft_itoa(num2);
    char *str3 = ft_itoa(num3);
    char *str4 = ft_itoa(num4);
    char *str5 = ft_itoa(num5);

    // Imprimimos los resultados
    printf("ft_itoa(%d) = %s\n", num1, str1);
    printf("ft_itoa(%d) = %s\n", num2, str2);
    printf("ft_itoa(%d) = %s\n", num3, str3);
    printf("ft_itoa(%d) = %s\n", num4, str4);
    printf("ft_itoa(%d) = %s\n", num5, str5);

    // Liberar la memoria de las cadenas generadas por itoa
    free(str1);
    free(str2);
    free(str3);
    free(str4);
    free(str5);

    return 0;
}

