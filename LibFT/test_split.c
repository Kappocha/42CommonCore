#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char **result;
    int i;

    // Caso 1: separación normal
    result = ft_split("hola mundo como estas", ' ');
    i = 0;
    while (result[i])
    {
        printf("result[%d]: '%s'\n", i, result[i]);
        free(result[i]);
        i++;
    }
    free(result);

    printf("\n");

    // Caso 2: separadores consecutivos y al inicio/final
    result = ft_split("  abc  def   ghi ", ' ');
    i = 0;
    while (result[i])
    {
        printf("result[%d]: '%s'\n", i, result[i]);
        free(result[i]);
        i++;
    }
    free(result);

    printf("\n");

    // Caso 3: string vacío
    result = ft_split("", ' ');
    if (result)
    {
        i = 0;
        while (result[i])
        {
            printf("result[%d]: '%s'\n", i, result[i]);
            free(result[i]);
            i++;
        }
        free(result);
    }
    else
        printf("result es NULL\n");

    printf("\n");

    // Caso 4: solo separadores
    result = ft_split("    ", ' ');
    if (result)
    {
        i = 0;
        while (result[i])
        {
            printf("result[%d]: '%s'\n", i, result[i]);
            free(result[i]);
            i++;
        }
        free(result);
    }
    else
        printf("result es NULL\n");

    return 0;
}

