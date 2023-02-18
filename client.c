/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:20:46 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/02/18 17:16:25 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signals(int pid, char *message)
{
	int	character;
	int	i;

	character = 0;
	while (message[character])
	{
		i = 0;
		while (i < 8)
		{
			if (((unsigned char)(message[character] >> (7 - i)) & 1) == 0)
				kill(pid, SIGUSR1);
			else if (((unsigned char)(message[character] >> (7 - i)) & 1) == 1)
				kill(pid, SIGUSR2);
			usleep(500);
			i++;
		}
		character++;
	}
	i = 0;
	while (i < 8)
	{
		kill(pid, SIGUSR1);
		usleep(500);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		server_id;
	char	*message;

	if (argc != 3)
		return (ft_printf("[ERROR] Enter 3 arguments\
in the terminal as follow: ./client <PID> <Message>"));
	else if (argc == 3)
	{
		server_id = ft_atoi(argv[1]);
		message = argv[2];
		send_signals(server_id, message);
	}
	return (0);
}
