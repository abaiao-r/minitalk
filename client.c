/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:20:46 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/02/16 19:52:52 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signals(int pid, char *message)
{
	int	characther;
	int	i;

	characther = 0;
	while (message[characther])
	{
		i = 0;
		while (i < 8)
		{
			if (((unsigned char)(message[characther] >> (8 - i)) & 1) == 0)
				kill(pid, SIGUSR1);
			else if (((unsigned char)(message[characther] >> (8 - i)) & 1) == 1)
				kill(pid, SIGUSR2);
			usleep(50);
			i++;
		}
		characther++;
	}
	i = 0;
	while (i < 8)
	{
		kill(pid, SIGUSR1);
		usleep(50);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		server_id;
	char	*message;

	if (argc != 3)
		return (ft_printf("[ERROR] Enter 3 arguments in the terminal as follow: ./client <PID> <Message>"));
	else if (argc == 3)
	{
		server_id = ft_atoi(argv[1]);
		message = argv[2];
		send_signals(server_id, message);
	}
	return (0);
}
