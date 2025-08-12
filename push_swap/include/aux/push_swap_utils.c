#include "../../push_swap.h"

// Verifica si stack_a está ordenado de menor a mayor
int is_sorted(Node *stacka) {
    while (stacka && stacka->next) {
        if (stacka->num > stacka->next->num)
            return 0;
        stacka = stacka->next;
    }
    return 1;
}

// Encuentra la posición (0-indexed) del nodo con el valor mínimo
int find_min_position(Node *stacka) {
    int pos = 0, min_pos = 0;
    int min = stacka->num;
    Node *curr = stacka;
    while (curr) {
        if (curr->num < min) {
            min = curr->num;
            min_pos = pos;
        }
        curr = curr->next;
        pos++;
    }
    return min_pos;
}
// Deja el mínimo arriba usando ra o rra según convenga
void final_rotate_to_min(Node **stacka, int *counter) {
    int min_pos = find_min_position(*stacka);
    int size = stack_size(*stacka);
    if (min_pos <= size / 2) {
        for (int i = 0; i < min_pos; i++) {
            ra(stacka);
            (*counter)++;
            printf("ra\n");
        }
    } else {
        for (int i = 0; i < size - min_pos; i++) {
            rra(stacka);
            (*counter)++;
            printf("rra\n");
        }
    }
}
