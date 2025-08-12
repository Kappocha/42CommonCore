#include "../../push_swap.h"

void rra(Node **stacka)
{
    Node *last;
    Node *penultimate;

    // Chequeo de seguridad: lista vacía o de un solo nodo
    if (*stacka == NULL || (*stacka)->next == NULL)
        return;

    // Encuentra el último nodo
    last = *stacka;
    while (last->next != NULL)
    {
        last = last->next;
    }

    // Encuentra el penúltimo nodo
    penultimate = last->prev;

    // Rompe el enlace del penúltimo con el último
    penultimate->next = NULL;

    // El último pasa a ser el primero
    last->next = *stacka;
    last->prev = NULL;
    (*stacka)->prev = last;

    // Actualiza el head de la lista
    *stacka = last;
}

void rrb(Node **stackb)
{
    Node *last;
    Node *penultimate;

    // Verifica que haya al menos dos nodos
    if (*stackb == NULL || (*stackb)->next == NULL)
        return;

    last = *stackb;
    // Avanza hasta el último nodo
    while (last->next != NULL)
        last = last->next;

    // Encuentra el penúltimo nodo
    penultimate = last->prev;

    if (penultimate != NULL)
        penultimate->next = NULL;
    // El último pasa a ser el primero
    last->next = *stackb;
    last->prev = NULL;
    (*stackb)->prev = last;
    // Actualiza el inicio de la lista
    *stackb = last;
}

void rrr(Node **stacka, Node **stackb)
{
    Node *last;
    Node *penultimate;

    if (*stacka && (*stacka)->next)
    {
        last = *stacka;
        while (last->next)
            last = last->next;
        penultimate = last->prev;
        penultimate->next = NULL;
        last->next = *stacka;
        last->prev = NULL;
        (*stacka)->prev = last;
        *stacka = last;
    }
    if (*stackb && (*stackb)->next)
    {
        last = *stackb;
        while (last->next)
            last = last->next;
        penultimate = last->prev;
        penultimate->next = NULL;
        last->next = *stackb;
        last->prev = NULL;
        (*stackb)->prev = last;
        *stackb = last;
    }
}
