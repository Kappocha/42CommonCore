#include "../../push_swap.h"

void start_stack(Node **stacka, Node **stackb, int *counter)
{
    int total = stack_size(*stacka);
    int i = 0;
    int to_move = total - 3;
    if (to_move <= 0)
        return;

    while (i < to_move && *stacka && stack_size(*stacka) > 3)
    {
        pb(stacka, stackb);
        i++;
        (*counter)++;
        ft_printf("pb\n");
    }
}

void sort_three(Node **stacka, int *count)
{
    if (!stacka || !*stacka)
        return;
    if (!(*stacka)->next || !(*stacka)->next->next)
        return;

    int a = (*stacka)->num;
    int b = (*stacka)->next->num;
    int c = (*stacka)->next->next->num;

    if (a > b && b < c && a < c)
    {
        sa(stacka);
        (*count)++;
        ft_printf("sa\n");
    }
    else if (a > b && b > c)
    {
        sa(stacka);
        (*count)++;
        ft_printf("sa\n");
        rra(stacka);
        (*count)++;
        ft_printf("rra\n");
    }
    else if (a > b && b < c && a > c)
    {
        ra(stacka);
        (*count)++;
        ft_printf("ra\n");
    }
    else if (a < b && b > c && a < c)
    {
        sa(stacka);
        (*count)++;
        ft_printf("sa\n");
        ra(stacka);
        (*count)++;
        ft_printf("ra\n");
    }
    else if (a < b && b > c && a > c)
    {
        rra(stacka);
        (*count)++;
        ft_printf("rra\n");
    }
}

int check_doubly_linked_list(Node *head)
{
    Node *current = head;
    Node *prev = NULL;
    while (current)
    {
        if (current->prev != prev)
        {
            ft_printf("Error\n");
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

        int common_move;
        if (best.moves_a > 0 && best.moves_b > 0)
        {
            if (best.moves_a < best.moves_b)
                common_move = best.moves_a;
            else
                common_move = best.moves_b;
            i = 0;
            while (i < common_move)
            {
                rr(stacka, stackb);
                (*counter)++;
                ft_printf("rr\n");
                i++;
                best.moves_a--;
                best.moves_b--;
            }
            
        }
        else if (best.moves_a < 0 && best.moves_b < 0)
        {
            if (-best.moves_a < -best.moves_b)
                common_move = -best.moves_a;
            else
                common_move = -best.moves_b;
            i = 0;
            while (i < common_move)
            {
                rrr(stacka, stackb);
                (*counter)++;
                ft_printf("rrr\n");
                i++;
                best.moves_a++;
                best.moves_b++;
            }
        }
        if (best.moves_b > 0)
        {
            i = 0;
            while (i < best.moves_b)
            {
                rb(stackb);
                (*counter)++;
                ft_printf("rb\n");
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
                ft_printf("rrb\n");
                i++;
            }
        }
        if (best.moves_a > 0)
        {
            i = 0;
            while (i < best.moves_a)
            {
                ra(stacka);
                (*counter)++;
                ft_printf("ra\n");
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
                ft_printf("rra\n");
                i++;
            }
        }
        pa(stacka, stackb);
        (*counter)++;
        ft_printf("pa\n");
    }
}
