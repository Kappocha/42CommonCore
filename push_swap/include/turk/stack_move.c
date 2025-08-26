#include "../../push_swap.h"

void start_stack(Node **stacka, Node **stackb, int *counter)
{
    int total = stack_size(*stacka);
    int i = 0;
    int to_move = total - 3;
    
    // Asegurarse de que no movemos más de lo necesario
    if (to_move <= 0)
        return;
    
    while (i < to_move && *stacka && stack_size(*stacka) > 3)
    {
        pb(stacka, stackb);
        i++;
        (*counter)++;
        printf("pb\n");
    }
}

void sort_three(Node **stacka, int *count)
{
    if (!stacka || !*stacka)
        return;
    
    // Verificar que hay al menos 3 elementos
    if (!(*stacka)->next || !(*stacka)->next->next)
        return;
    
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
        t_move best = calc_best_move(*stacka, *stackb);
        
        // Posicionar stack B para el elemento óptimo
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
        
        // Posicionar stack A para recibir el elemento
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
        
        // Mover el elemento
        pa(stacka, stackb);
        (*counter)++;
        printf("pa\n");
    }
}
