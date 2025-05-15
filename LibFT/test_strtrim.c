#include "libft.h"
#include <stdio.h>

int main(void)
{
    char *s1 = "   \t\nHola mundo\n\t   ";
    char *s2 = "xxxyHola mundo y másxxx";
    char *s3 = "*****";
    char *s4 = "";
    char *s5 = NULL;

    char *set1 = " \t\n";
    char *set2 = "x*y";
    char *set3 = "*";
    char *set4 = " ";

    char *res1 = ft_strtrim(s1, set1);
    char *res2 = ft_strtrim(s2, set2);
    char *res3 = ft_strtrim(s3, set3);
    char *res4 = ft_strtrim(s4, set4);
    char *res5 = ft_strtrim(s5, set1);

    printf("Caso 1: '%s'\n", res1);
    printf("Caso 2: '%s'\n", res2);
    printf("Caso 3: '%s'\n", res3);
    printf("Caso 4: '%s'\n", res4);
    printf("Caso 5: %s\n", res5 ? res5 : "(null)");

    free(res1);
    free(res2);
    free(res3);
    free(res4);
    free(res5);

    return 0;
}

