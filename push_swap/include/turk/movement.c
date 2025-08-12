#include "../../push_swap.h"

int calc_move_a(Node *stacka, int target)
{
    int size = stack_size(stacka); // Necesitas una función para esto
    int pos = find_insert_position(stacka, target); // Posición donde debe ir el número

    if (pos <= size / 2)
        return pos; //rb
    else
        return pos - size; //rrb
}

int calc_move_b(Node *stackb, int pos)
{
    int size = stack_size(stackb);
    if (pos <= size / 2)
        return pos;         // rb
    else
        return pos - size; // rrb (negativo)
}

t_move calc_best_move(Node *stacka, Node *stackb)
{
    t_move best;
    int i;
    Node *tmpb;

    tmpb = stackb;
    best.total = 2147483647;
    i = 0;
    while (tmpb) {
        t_move actual;
        actual.index_b = i;
        actual.moves_b = calc_move_b(stackb, i);
        actual.moves_a = calc_move_a(stacka, tmpb->num);
        actual.total = absolute(actual.moves_a) + absolute(actual.moves_b);
        if (actual.total < best.total)
            best = actual;
        tmpb = tmpb->next;
        i++;
    }
    return best;
}
