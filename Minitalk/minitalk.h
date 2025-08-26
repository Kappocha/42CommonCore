#ifndef MINITALK_H
#define MINITALK_H

#define _GNU_SOURCE
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include "libft/libft.h"

typedef struct s_data
{
    pid_t   pid;
    char    *msg;
    int     bit;
    int     current_char;
    int     bit_count;
}   t_data;

// Prototipos de funciones
void    ft_send_message(pid_t pid, char *msg);
void    ft_send_bit(pid_t pid, int bit);
void    ft_handler(int sig, siginfo_t *info, void *context);


#endif