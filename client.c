/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:20:46 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/02/22 16:19:09 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		g_message_length;

int	ft_strlen(char *message)
{
	int	i;

	i = 0;
	while (message[i])
		i++;
	return (i);
}

void	signal_handler(int signal)
{
	static int	i;

	if (signal == SIGUSR2)
	{
		i++;
		if (i == g_message_length)
			ft_printf("Message received");
	}
}

/* The send_signals function takes the server PID and message as 
parameters and sends the message character by character to the 
server using signals. It uses two different signals to represent 
0 and 1 bits of the message, respectively: SIGUSR1 and SIGUSR2.
The message is sent character by character, and each character is 
sent bit by bit. The outer loop iterates over each character of 
the message, and the inner loop iterates over each bit of the 
character. The rightmost (least significant) bit is sent first.
If the bit being sent is 0, the client sends a SIGUSR1 signal 
to the server. If the bit is 1, it sends a SIGUSR2 signal. 
The usleep function is called after each signal to introduce a 
small delay, allowing the server to handle the signal before the 
next one is sent. After sending all the characters in the message, 
the function sends 8 SIGUSR1 signals to indicate the end of the message.
 */
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

/* The program takes in two arguments from the command line: 
the first argument is the process ID (PID) of the server program, 
and the second argument is the message that the client wants to 
send to the server.*/
int	main(int argc, char **argv)
{
	int		server_id;
	char	*message;

	g_message_length = ft_strlen(argv[2]);
	if (argc != 3)
		return (ft_printf("[ERROR] Enter 3 arguments\
in the terminal as follow: ./client <PID> <Message>"));
	else if (argc == 3)
	{
		server_id = ft_atoi(argv[1]);
		message = argv[2];
		signal(SIGUSR2, signal_handler);
		send_signals(server_id, message);
		send_signals(server_id, "\n");
	}
	return (0);
}
