#include "push_swap.h"

int main(int argc, char **argv)
{
    Node *stack_a;
    Node *stack_b;
    int contador = 0;

    stack_b = NULL;
    stack_a = start_nodes(argc, argv);
    if (!stack_a)
    {
        printf("Error al inicializar la lista\n");
        return (1);
    }
    start_stack(&stack_a, &stack_b, &contador);
    sort_three(&stack_a, &contador);
    move_all_b_to_a(&stack_a, &stack_b, &contador);
    final_rotate_to_min(&stack_a, &contador);
    free_list(stack_a);
    return (0);
}
