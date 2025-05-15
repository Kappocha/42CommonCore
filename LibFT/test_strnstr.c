#include "libft.h"
#include <stdio.h>

int main(void)
{
    const char *haystack = "Hola, este es un ejemplo.";
    const char *needle1 = "este";
    const char *needle2 = "ejemplo";
    const char *needle3 = "noesta";
    const char *needle4 = "";
    
    char *res1 = ft_strnstr(haystack, needle1, 20);
    char *res2 = ft_strnstr(haystack, needle2, 10);
    char *res3 = ft_strnstr(haystack, needle3, 25);
    char *res4 = ft_strnstr(haystack, needle4, 5);   // Búsqueda de cadena vacía

    printf("Caso 1: %s\n", res1 ? res1 : "(null)");
    printf("Caso 2: %s\n", res2 ? res2 : "(null)");
    printf("Caso 3: %s\n", res3 ? res3 : "(null)");
    printf("Caso 4: %s\n", res4 ? res4 : "(null)");

    return 0;
}

