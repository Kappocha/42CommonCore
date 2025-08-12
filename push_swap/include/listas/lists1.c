#include "../../push_swap.h"

void sa(Node **stacka)
{
    if (stacka && (*stacka)->next) {
        int tmp;
        tmp = (*stacka)->num;
        (*stacka)->num  = (*stacka)->next->num;
        (*stacka)->next->num = tmp;
    }
}

void sb(Node **stackb)
{
    if (stackb && (*stackb)->next)
    {
        int tmp;
        tmp = (*stackb)->num;
        (*stackb)->num = (*stackb)->next->num;
        (*stackb)->next->num = tmp;
    }
}

void ss (Node **stacka, Node **stackb)
{
    if (stacka && (*stacka)->next)
    {
        int tmp;
        tmp = (*stacka)->num;
        (*stacka)->num = (*stacka)->next->num;
        (*stacka)->next->num = tmp;
    }
    if (stackb && (*stackb)->next)
    {
        int tmp;
        tmp = (*stackb)->num;
        (*stackb)->num = (*stackb)->next->num;
    }
}

void    pa(Node **stacka, Node **stackb)
{
    Node *tmp;

    if (*stackb == NULL)
        return;

    tmp = *stackb;
    *stackb = (*stackb)->next;

    if (*stackb)
        (*stackb)->prev = NULL;

    tmp->next = *stacka;
    if (*stacka)
        (*stacka)->prev = tmp;
    tmp->prev = NULL;
    *stacka = tmp;
}

void    pb(Node **stacka, Node **stackb)
{
    Node *tmp;

    if (*stacka == NULL)
        return;

    tmp = *stacka;
    *stacka = (*stacka)->next;

    if (*stacka)
        (*stacka)->prev = NULL;

    tmp->next = *stackb;
    if (*stackb)
        (*stackb)->prev = tmp;
    tmp->prev = NULL;
    *stackb = tmp;
}
