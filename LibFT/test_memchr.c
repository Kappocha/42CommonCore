#include <stdio.h>
#include <string.h>  // Para comparar con la función estándar de memchr
#include "libft.h"

int main(void)
{
    // Datos de prueba
    const char str[] = "Hola, mundo!";
    char target1 = 'm';  // Carácter que está en la cadena
    char target2 = 'z';  // Carácter que no está en la cadena
    char target3 = ',';  // Carácter especial en la cadena
    char target4 = ' ';  // Carácter en el medio de la cadena

    // Usamos ft_memchr
    void *result1 = ft_memchr(str, target1, sizeof(str)); // Buscando 'm'
    void *result2 = ft_memchr(str, target2, sizeof(str)); // Buscando 'z'
    void *result3 = ft_memchr(str, target3, sizeof(str)); // Buscando ','
    void *result4 = ft_memchr(str, target4, sizeof(str)); // Buscando ' '

    // Comparar con la función estándar memchr
    void *std_result1 = memchr(str, target1, sizeof(str));
    void *std_result2 = memchr(str, target2, sizeof(str));
    void *std_result3 = memchr(str, target3, sizeof(str));
    void *std_result4 = memchr(str, target4, sizeof(str));

    // Imprimimos los resultados
    printf("Buscando '%c' con ft_memchr: %s\n", target1, (result1 ? (char*)result1 : "No encontrado"));
    printf("Buscando '%c' con ft_memchr: %s\n", target2, (result2 ? (char*)result2 : "No encontrado"));
    printf("Buscando '%c' con ft_memchr: %s\n", target3, (result3 ? (char*)result3 : "No encontrado"));
    printf("Buscando '%c' con ft_memchr: %s\n", target4, (result4 ? (char*)result4 : "No encontrado"));

    // Comprobamos que las implementaciones son consistentes
    printf("\nComparando con la versión estándar:\n");
    printf("Buscando '%c' con memchr: %s\n", target1, (std_result1 ? (char*)std_result1 : "No encontrado"));
    printf("Buscando '%c' con memchr: %s\n", target2, (std_result2 ? (char*)std_result2 : "No encontrado"));
    printf("Buscando '%c' con memchr: %s\n", target3, (std_result3 ? (char*)std_result3 : "No encontrado"));
    printf("Buscando '%c' con memchr: %s\n", target4, (std_result4 ? (char*)std_result4 : "No encontrado"));

    return 0;
}
