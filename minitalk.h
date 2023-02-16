/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:07:46 by andrefranci       #+#    #+#             */
/*   Updated: 2023/02/16 19:26:57 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H


# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include "minitalk.h"
# include <stdio.h>
# include <stdarg.h>
# include <string.h>

int	ft_printf(const char *s, ...);
int	ft_atoi(const char *nptr);

#endif
