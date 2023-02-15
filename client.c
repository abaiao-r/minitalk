/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:20:46 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/02/15 17:50:43 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	int server_id;
	char *message;

	if (argv != 3)
		return (write(2, "Write only 3 arguments!", 23));
	else if (argv == 3)
	{
		server_id = ft_atoi(argv[1]);
		message = argv[2];
		send_signals(server_id, message);
	}
}