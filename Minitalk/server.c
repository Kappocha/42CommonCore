#include "minitalk.h"

void ft_handler(int sig, siginfo_t *info, void *context)
{
    static int current_char = 0;
    static int bit_count = 0;
    (void)context;
    
    // Recibir bit: SIGUSR1 = 0, SIGUSR2 = 1
    if (sig == SIGUSR1)
        current_char = (current_char << 1) | 0;
    else if (sig == SIGUSR2)
        current_char = (current_char << 1) | 1;
    
    bit_count++;
    
    // Si hemos recibido 8 bits (1 carácter completo)
    if (bit_count == 8)
    {
        // Si es carácter nulo, fin del mensaje
        if (current_char == 0)
        {
            ft_putstr("\n");
            // Enviar confirmación al cliente
            kill(info->si_pid, SIGUSR1);
        }
        else
        {
            // Imprimir el carácter recibido
            write(1, &current_char, 1);
        }
        
        // Resetear para el siguiente carácter
        current_char = 0;
        bit_count = 0;
    }
}

int main(void)
{
    struct sigaction sa;
    
    ft_putstr("ID del servidor: ");
    ft_putnbr(getpid());
    ft_putstr("\nEsperando mensajes...\n");
    
    // Configurar el manejador de señales
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = ft_handler;
    sigemptyset(&sa.sa_mask);
    
    // Registrar los manejadores
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    
    // Bucle infinito esperando señales
    while (1)
        pause();
        
    return (0); 
}