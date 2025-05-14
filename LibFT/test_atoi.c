#include "libft.h"
#include <stdio.h>

int main(void)
{
    const char *caso1;
    const char *caso2;
    int resultado1;
    int resultado2;

    caso1 = "12345";
    caso2 = "   -6789";

    resultado1 = ft_atoi(caso1);
    resultado2 = ft_atoi(caso2);

    printf("Entrada: \"%s\" → Resultado: %d\n", caso1, resultado1);
    printf("Entrada: \"%s\" → Resultado: %d\n", caso2, resultado2);

    return 0;
}
