#include "../../push_swap.h"

void ra(Node **stacka)
{
    Node *first;
    Node *last;

    if (*stacka == NULL || (*stacka)->next == NULL)
        return;

    first = *stacka;
    *stacka = first->next;
    (*stacka)->prev = NULL;

    last = *stacka;
    while (last->next != NULL)
        last = last->next;

    last->next = first;
    first->prev = last;
    first->next = NULL;
}

void rb(Node **stackb)
{
    Node *first;
    Node *last;

    if (*stackb == NULL || (*stackb)->next == NULL)
        return;

    first = *stackb;
    *stackb = first->next;
    (*stackb)->prev = NULL;

    last = *stackb;
    while (last->next != NULL)
        last = last->next;

    last->next = first;
    first->prev = last;
    first->next = NULL;
}

void rr(Node **stacka, Node **stackb)
{
    Node *firsta;
    Node *lasta;
    Node *firstb;
    Node *lastb;

    if (*stacka != NULL && (*stacka)->next != NULL)
    {
        firsta = *stacka;
        *stacka = firsta->next;
        lasta = *stacka;
        while (lasta->next != NULL)
            lasta = lasta->next;
        lasta->next = firsta;
        firsta->next = NULL;
    }
    if (*stackb != NULL && (*stackb)->next != NULL)
    {
        firstb = *stackb;
        *stackb = firstb->next;
        lastb = *stackb;
        while (lastb->next != NULL)
            lastb = lastb->next;
        lastb->next = firstb;
        firstb->next = NULL;
    }
}
