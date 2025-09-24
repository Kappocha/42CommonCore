#include "minitalk.h"

void	ft_send_bit(pid_t pid, int bit)
{
	if (bit == 0)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	usleep(500);
}

void	ft_send_message(pid_t pid, char *msg)
{
	int		i;
	int		bit_pos;
	char	current_char;

	i = 0;
	while (msg[i])
	{
		current_char = msg[i];
		bit_pos = 7;
		while (bit_pos >= 0)
		{
			if ((current_char >> bit_pos) & 1)
				ft_send_bit(pid, 1);
			else
				ft_send_bit(pid, 0);
			bit_pos--;
		}
		i++;
	}
	bit_pos = 7;
	while (bit_pos >= 0)
	{
		ft_send_bit(pid, 0);
		bit_pos--;
	}
}

int	main(int argv, char **argc)
{
	pid_t	server_pid;
	char	*message;

	if (argv != 3)
	{
		ft_putstr("Usage: ./client <PID> <message>\n");
		return (1);
	}
	server_pid = (pid_t)ft_atoi(argc[1]);
	message = argc[2];
	if (server_pid <= 0)
	{
		ft_putstr("Error: PID inválido\n");
		return (1);
	}
	ft_putstr("Enviando mensaje: ");
	ft_putstr(message);
	ft_putstr("\n");
	ft_send_message(server_pid, message);
	ft_putstr("Mensaje enviado exitosamente\n");
	return (0);
}
