#include "libft.h"
#include <stdio.h>

int main(void)
{
    char *s1 = "Hola, mundo!";
    char *s2 = "";
    char *s3 = "12345";

    char *sub1 = ft_substr(s1, 0, 4);      // "Hola"
    char *sub2 = ft_substr(s1, 7, 5);      // "mundo"
    char *sub3 = ft_substr(s1, 20, 5);     // start fuera del rango, debería devolver ""
    char *sub4 = ft_substr(s2, 0, 10);     // cadena vacía
    char *sub5 = ft_substr(s3, 2, 10);     // len más largo que lo que queda desde start → "345"

    printf("sub1: '%s'\n", sub1);
    printf("sub2: '%s'\n", sub2);
    printf("sub3: '%s'\n", sub3);
    printf("sub4: '%s'\n", sub4);
    printf("sub5: '%s'\n", sub5);

    // Liberar memoria si ft_substr usa malloc
    free(sub1);
    free(sub2);
    free(sub3);
    free(sub4);
    free(sub5);

    return 0;
}
