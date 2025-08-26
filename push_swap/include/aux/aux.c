#include "../../push_swap.h"

int absolute(int a)
{
    if (a < 0)
        return (-a);
    return (a);
}

int stack_size(Node *stack)
{
    Node *tmp;
    int i;

    tmp = stack;
    i = 0;
    while (tmp)
    {
        tmp = tmp->next;
        i++;
    }
    return (i);
}

int find_insert_position(Node *stack, int target)
{
    int i = 0;
    Node *tmp = stack;
    Node *min_node = stack;
    int min_val;
    
    if (!stack)
        return 0;
    
    // Encontrar el mínimo del stack
    min_val = stack->num;
    tmp = stack;
    while (tmp)
    {
        if (tmp->num < min_val)
        {
            min_val = tmp->num;
            min_node = tmp;
        }
        tmp = tmp->next;
    }
    
    // Si target es menor que el mínimo, debe ir antes del mínimo
    if (target < min_val)
    {
        i = 0;
        tmp = stack;
        while (tmp != min_node)
        {
            tmp = tmp->next;
            i++;
        }
        return i;
    }
    
    // Buscar la posición correcta: después del mayor número que sea menor que target
    i = 0;
    tmp = stack;
    int best_pos = 0;
    int best_val = -2147483648; // Valor muy pequeño
    
    while (tmp)
    {
        if (tmp->num < target && tmp->num > best_val)
        {
            best_val = tmp->num;
            best_pos = i;
        }
        tmp = tmp->next;
        i++;
    }
    
    return (best_pos + 1) % stack_size(stack);
}
