/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:21:00 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/02/16 19:40:18 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_pow(int nb, int power)
{
	int	result;
	int	i;

	if (power == 0)
		return (1);
	else if (power < 0)
		return (0);
	else
	{
		i = 1;
		result = nb;
		while (i != power)
		{
			result = result * nb;
			i++;
		}
	}
	return (result);
}

void	binary_to_text(char *s)
{
	int	decimal;
	int	power;
	int	i;

	decimal = 0;
	power = 0;
	i = 7;
	while (i >= 0)
	{
		if (s[i] == '1')
		{
			decimal = decimal + (int)ft_pow(2, power);
		}
		power++;
		i--;
		ft_printf("%c", ((char)decimal));
		i = i + 8;
	}
}

void	signal_handler(int signum)
{
	static int	i;
	static char	message_binary[8];

	i = 0;
	if (signum == SIGUSR1)
		message_binary[i] = '0';
	else if (signum == SIGUSR2)
		message_binary[i] = '1';
	i++;
	if (i == 8)
	{
		i = 0;
		binary_to_text(message_binary);
	}
}

int	main(void)
{
	struct sigaction	signal_received;

	ft_printf("abaiao-r server online\nServer's PID: %d\n", getpid());
	signal_received.sa_handler = signal_handler;
	signal_received.sa_flags = 0;
	sigaction(SIGUSR1, &signal_received, NULL);
	sigaction(SIGUSR2, &signal_received, NULL);
	while (1)
		usleep(50);
	return (0);
}

/* main to test binary_to_text function */
/* int	main(void)
{
	char	*s;

	s = "0100100";
	binary_to_text(s);
} */

/* main to test ft_power */
/* int	main(void)
{
	int	nb;
	int	power;

	nb = 0;
	power = 1;
	ft_printf("%d", ft_pow(nb, power));
} */