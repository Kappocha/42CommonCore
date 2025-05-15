#include "libft.h"
#include <stdio.h>

int main(void)
{
    const char *str1 = "Hola";
    const char *str2 = "";
    const char *str3 = "1234567890";
    const char *str4 = "¡Hola, mundo!";
    const char *str5 = "Línea\nNueva";

    printf("ft_strlen(\"%s\") = %zu\n", str1, ft_strlen(str1));
    printf("ft_strlen(\"%s\") = %zu\n", str2, ft_strlen(str2));
    printf("ft_strlen(\"%s\") = %zu\n", str3, ft_strlen(str3));
    printf("ft_strlen(\"%s\") = %zu\n", str4, ft_strlen(str4));
    printf("ft_strlen(\"%s\") = %zu\n", str5, ft_strlen(str5));

    return 0;
}

