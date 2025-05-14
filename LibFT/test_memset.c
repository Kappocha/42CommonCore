#include <stdio.h>
#include <string.h>
#include "libft.h"

int main(void)
{
    char str1[20] = "Hola mundo";
    char str2[20] = "1234567890";
    char str3[20] = "ABCDE";

    printf("Antes de ft_memset:\n");
    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);
    printf("str3: %s\n", str3);

    ft_memset(str1 + 5, '*', 3);   // Sustituye parte del medio
    ft_memset(str2, '-', 10);      // Toda la cadena
    ft_memset(str3 + 2, 0, 2);     // Sustituye con \0 (nulls)

    printf("\nDespués de ft_memset:\n");
    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);
    printf("str3: ");
    for (int i = 0; i < 5; i++)
    {
        if (str3[i])
            printf("%c", str3[i]);
        else
            printf("\\0");
    }
    printf("\n");

    return 0;
}

