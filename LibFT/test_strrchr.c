#include "libft.h"
#include <stdio.h>

int main(void)
{
    char *s1 = "Hola mundo";
    char *s2 = "abcabcabc";
    char *s3 = "";
    char *s4 = "termina en punto.";
    char c1 = 'o';
    char c2 = 'a';
    char c3 = 'x';
    char c4 = '\0';

    char *res1 = ft_strrchr(s1, c1);  // Última 'o'
    char *res2 = ft_strrchr(s2, c2);  // Última 'a'
    char *res3 = ft_strrchr(s3, c3);  // En cadena vacía, buscar 'x'
    char *res4 = ft_strrchr(s4, '.'); // Buscar '.'
    char *res5 = ft_strrchr(s1, c4);  // Buscar '\0'

    printf("Caso 1: %s\n", res1 ? res1 : "(null)");
    printf("Caso 2: %s\n", res2 ? res2 : "(null)");
    printf("Caso 3: %s\n", res3 ? res3 : "(null)");
    printf("Caso 4: %s\n", res4 ? res4 : "(null)");
    printf("Caso 5: %s\n", res5 ? res5 : "(null)");

    return 0;
}
