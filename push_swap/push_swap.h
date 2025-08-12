#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int num;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct s_move {
    int moves_a;
    int moves_b;
    int total;
    int index_b;
}   t_move;

void    sa(Node **stacka);
void    sb(Node **stackb);
void    ss(Node **stacka, Node **stackb);
void    pa(Node **stacka, Node **stackb);
void    pb(Node **stacka, Node **stackb);
void    ra(Node **stacka);
void    rb(Node **stackb);
void    rr(Node **stacka, Node **stackb);
void    rra(Node **stacka);
void    rrb(Node **stackb);
void    rrr(Node **stacka, Node **stackb);
Node    *start_nodes(int argc, char **argv);
void    free_list(Node *head);
int absolute(int a);
int find_insert_position(Node *stack, int target);
int stack_size(Node *stack);
t_move calc_best_move(Node *stacka, Node *stackb);
void start_stack(Node **stacka, Node **stackb, int *counter);
void move_all_b_to_a(Node **stacka, Node **stackb, int *counter);
void final_rotate_to_min(Node **stacka, int *counter);
int check_doubly_linked_list(Node *head);
int is_sorted(Node *stacka);
void sort_three(Node **stacka, int *count);

# endif
