/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:21:00 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/02/22 15:35:27 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/* The ft_pow function calculates the power of 
an integer number. It takes two arguments: nb, 
which is the base, and power, which is the exponent. 
The function returns an integer representing nb 
raised to the power of power.

The function first checks whether power is 0 or 
negative. If power is 0, the function returns 1, 
since any number raised to the power of 0 is 1. 
If power is negative, the function returns 0, 
since raising a number to a negative power is not 
a real number.

If power is positive, the function initializes a 
counter variable i to 1 and a result variable result 
to nb. It then enters a while loop that continues as 
long as i is less than power. In each iteration of 
the loop, result is multiplied by nb, and i is 
incremented. After the loop exits, the function 
returns result, which is nb raised to the power of power. */
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

/* This is a function that takes a binary string as 
input and converts it to a character based on the ASCII 
table. The function starts by setting the initial values 
of three variables: "decimal", "power", and "i". The 
variable "decimal" is used to store the decimal value 
of the binary string, "power" is used to store the power 
of 2, and "i" is used as a counter for the while loop.

The function then enters a loop that runs 8 times, once 
for each bit in the binary string. The loop starts with 
"i" set to 7 and decrements "i" in each iteration. For 
each bit, the function checks if the bit is set to 1, and 
if so, it adds the corresponding power of 2 to "decimal" 
by calling the "ft_pow" function.

After all 8 bits have been processed, the function uses 
the decimal value to determine the corresponding character 
based on the ASCII table. It prints the character using the 
"ft_printf" function and increments "i" by 8 to reset it for 
the next binary string to be converted. */
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
	}
	ft_printf("%c", ((char)decimal));
	i = i + 8;
}

/* The function takes three arguments: the signal number (sig), a 
pointer to a siginfo_t structure containing information about the 
signal (info), and a pointer to a ucontext_t structure containing 
information about the signal context (ucontext). In this case, the 
ucontext argument is not used and can be safely ignored.

The function first ignores the ucontext and info arguments to avoid 
unused variable warnings. It then checks the signal number to determine 
whether the signal is SIGUSR1 or SIGUSR2. If the signal is SIGUSR1, it 
appends a '0' to the binary message stored in the message_binary array. 
If the signal is SIGUSR2, it appends a '1'.

Once eight signals have been received (i.e., once the message_binary 
array is full), the function converts the binary message to text using 
the binary_to_text function and prints it using ft_printf. Finally, the 
message_binary array is reset to all zeros using ft_memset, and the process 
begins again to receive the next message. */
void	signal_handler(int sig, siginfo_t *info, void *ucontext)
{
	static int	i;
	static char	message_binary[9];

	(void)ucontext;
	(void)info;
	if (sig == SIGUSR1)
		message_binary[i] = '0';
	else if (sig == SIGUSR2)
		message_binary[i] = '1';
	i++;
	if (i == 8)
	{
		message_binary[i] = '\0';
		i = 0;
		binary_to_text(message_binary);
		ft_memset(message_binary, 0, 8);
		kill(info->si_pid, SIGUSR2);
	}
}

/*  The server listens for two signals: SIGUSR1 and SIGUSR2. When a signal 
is received, the signal handler function signal_handler is called. The main 
function sets up the signal handler using the sigaction function and waits 
for signals to be received using the pause function.*/
int	main(void)
{
	struct sigaction	signal_received;

	ft_printf("abaiao-r server online\nServer's PID: %d\n", getpid());
	signal_received.sa_sigaction = signal_handler;
	signal_received.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &signal_received, NULL);
	sigaction(SIGUSR2, &signal_received, NULL);
	while (1)
		pause();
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