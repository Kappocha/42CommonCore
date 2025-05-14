#include <stdio.h>
#include <string.h>
#include "libft.h"

int main(void)
{
    char str1[] = "Hola, mundo!                            ";
    char str2[] = "abcdefg                                 ";
    char str3[] = "Hola, mundo!                            ";
    char str4[] = "memmove en C                            ";
    char str5[] = "Este es un test con solapamiento        ";

    char std1[] = "Hola, mundo!                            ";
    char std2[] = "abcdefg                                 ";
    char std3[] = "Hola, mundo!                            ";
    char std4[] = "memmove en C                            ";
    char std5[] = "Este es un test con solapamiento        ";

    ft_memmove(str1 + 5, str1, 5);
    ft_memmove(str2 + 3, str2, 4);
    ft_memmove(str3 + 5, str3, 8);
    ft_memmove(str4 + 4, str4, 9);
    ft_memmove(str5 + 5, str5, 9);

    memmove(std1 + 5, std1, 5);
    memmove(std2 + 3, std2, 4);
    memmove(std3 + 5, std3, 8);
    memmove(std4 + 4, std4, 9);
    memmove(std5 + 5, std5, 9);

    printf("ft_memmove(str1 + 5) = %s\n", str1);
    printf("memmove(std1 + 5)    = %s\n\n", std1);

    printf("ft_memmove(str2 + 3) = %s\n", str2);
    printf("memmove(std2 + 3)    = %s\n\n", std2);

    printf("ft_memmove(str3 + 5) = %s\n", str3);
    printf("memmove(std3 + 5)    = %s\n\n", std3);

    printf("ft_memmove(str4 + 4) = %s\n", str4);
    printf("memmove(std4 + 4)    = %s\n\n", std4);

    printf("ft_memmove(str5 + 5) = %s\n", str5);
    printf("memmove(std5 + 5)    = %s\n", std5);

    return 0;
}
