#include "../../push_swap.h"

void start_stack(Node **stacka, Node **stackb, int *counter)
{
    int total = stack_size(*stacka);
    int i = 0;
    while (i < total - 3 && *stacka)
    {
        pb(stacka, stackb);
        i++;
        (*counter)++;
        printf("pb\n");
    }
}

void sort_three(Node **stacka, int *count)
{
    int a = (*stacka)->num;
    int b = (*stacka)->next->num;
    int c = (*stacka)->next->next->num;

    if (a > b && b < c && a < c)
    {
        sa(stacka);
        (*count)++;
        printf("sa\n");
    }
    else if (a > b && b > c)
    {
        sa(stacka);
        (*count)++;
        printf("sa\n");
        rra(stacka);
        (*count)++;
        printf("rra\n");
    }
    else if (a > b && b < c && a > c)
    {
        ra(stacka);
        (*count)++;
        printf("ra\n");
    }
    else if (a < b && b > c && a < c)
    {
        sa(stacka);
        (*count)++;
        printf("sa\n");
        ra(stacka);
        (*count)++;
        printf("ra\n");
    }
    else if (a < b && b > c && a > c)
    {
        rra(stacka);
        (*count)++;
        printf("rra\n");
    }
    // Si está ordenado (1 2 3), no hace falta nada
}

int check_doubly_linked_list(Node *head)
{
    Node *current = head;
    Node *prev = NULL;
    while (current)
    {
        if (current->prev != prev)
        {
            printf("Error de integridad: nodo %p prev=%p (debería ser %p)\n",
                   (void*)current, (void*)current->prev, (void*)prev);
            return 0;
        }
        prev = current;
        current = current->next;
    }
    return 1;
}

void move_all_b_to_a(Node **stacka, Node **stackb, int *counter)
{
    int i;
    while (*stackb)
    {
        t_move best;
        Node *current;
        int min_total;

        min_total = 2147483647;
        current = *stackb;

        while (current)
        {
            t_move move = calc_best_move(*stacka, current);
            //printf("%i, %i, %i, %i \n", move.moves_a, move.moves_b, move.index_b, move.total);
            if (move.total < min_total)
            {
                min_total = move.total;
                best = move;
            }
            current = current->next;
        }
        if (best.moves_a > 0)
        {
            i = 0;
            while (i < best.moves_a)
            {
                ra(stacka);
                (*counter)++;
                printf("ra\n");
                i++;
            }
        }
        else if (best.moves_a < 0)
        {
            i = 0;
            while (i < -best.moves_a)
            {
                rra(stacka);
                (*counter)++;
                printf("rra\n");
                i++;
            }
        }
        if (best.moves_b > 0)
        {
            i = 0;
            while (i < best.moves_b)
            {
                rb(stackb);
                (*counter)++;
                printf("rb\n");
                i++;
            }
        }
        else if (best.moves_b < 0)
        {
            i = 0;
            while (i < -best.moves_b)
            {
                rrb(stackb);
                (*counter)++;
                printf("rrb\n");
                i++;
            }
        }
        (*counter)++;
        printf("pa\n");
        pa(stacka, stackb);
    }
}
