#include "../../push_swap.h"

void free_list(Node *head)
{
    Node *tmp;

    while (head != NULL)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

int no_dup(int argc, char **argv)
{
    int i;
    int j;
    int tmp, cmp;

    i = 1;
    while (i < argc - 1)
    {
        tmp = ft_atoi(argv[i]);
        j = i + 1;
        while (j < argc)
        {
            cmp = ft_atoi(argv[j]);
            if (tmp == cmp)
                return (0); // Duplicado encontrado
            j++;
        }
        i++;
    }
    return (1); // No hay duplicados
}

Node *start_nodes(int argc, char **argv)
{
    Node *head = NULL;
    Node *tail = NULL;
    Node *new;
    int i = 1;

    if (!no_dup(argc, argv))
        return NULL;
    while (i < argc)
    {
        new = malloc(sizeof(Node));
        if (!new)
        {
            printf("Error\n");
            free_list(head); // Libera lo que ya se había creado
            return NULL;
        }
        new->num = ft_atoi(argv[i]);
        new->next = NULL;
        new->prev = tail;
        if (tail)
            tail->next = new;
        else
            head = new;
        tail = new;
        i++;
    }
    return head;
}
