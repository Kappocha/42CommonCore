#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *s1;
    char *s2;
    char *result;

    // Caso 1: cadenas normales
    s1 = "Hola, ";
    s2 = "mundo!";
    result = ft_strjoin(s1, s2);
    if (result)
    {
        printf("'%s' + '%s' = '%s'\n", s1, s2, result);
        free(result);
    }

    // Caso 2: s1 vacío
    s1 = "";
    s2 = "cadena";
    result = ft_strjoin(s1, s2);
    if (result)
    {
        printf("'%s' + '%s' = '%s'\n", s1, s2, result);
        free(result);
    }

    // Caso 3: s2 vacío
    s1 = "cadena";
    s2 = "";
    result = ft_strjoin(s1, s2);
    if (result)
    {
        printf("'%s' + '%s' = '%s'\n", s1, s2, result);
        free(result);
    }

    // Caso 4: ambas vacías
    s1 = "";
    s2 = "";
    result = ft_strjoin(s1, s2);
    if (result)
    {
        printf("'%s' + '%s' = '%s'\n", s1, s2, result);
        free(result);
    }

    return 0;
}
