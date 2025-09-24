#include "minitalk.h"

void	ft_handler(int sig, siginfo_t *info, void *context)
{
	static unsigned int	current_char = 0;
	static int			bit_count = 0;
	unsigned char		byte_to_write;

	(void)context;
	if (sig == SIGUSR1)
		current_char = (current_char << 1) | 0;
	else if (sig == SIGUSR2)
		current_char = (current_char << 1) | 1;
	bit_count++;
	if (bit_count == 8)
	{
		if (current_char == 0)
		{
			ft_putstr("\n");
			kill(info->si_pid, SIGUSR1);
		}
		else
		{
			byte_to_write = (unsigned char)current_char;
			write(1, &byte_to_write, 1);
		}
		current_char = 0;
		bit_count = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_putstr("ID del servidor: ");
	ft_putnbr(getpid());
	ft_putstr("\nEsperando mensajes...\n");
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ft_handler;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
