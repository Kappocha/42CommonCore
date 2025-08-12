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
    while (tmp)
    {
        if (tmp->num > target)
            return i;
        tmp = tmp->next;
        i++;
    }
    return i;
}
