# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/21 16:08:07 by abaiao-r          #+#    #+#              #
#    Updated: 2023/02/13 18:31:51 by abaiao-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CLIENT = client
NAME_SERVER = server

SRC_CLIENT = client.c \
SRC_SERVER = server.c \
		

OBJS_CLIENT = $(SRC_CLIENT:.c=.o)
OBJS_SERVER = $(SRC_SERVER:.c=.o)


CFLAGS = -Wall -Wextra -Werror -g

CC= cc 

RM = rm -rf 


all: $(NAME_CLIENT) $(NAME_SERVER)
	
$(NAME_CLIENT): $(OBJS_CLIENT)
		$(CC) $(CFLAGS) $(SRC_CLIENT) -o $(NAME_CLIENT) minitalk.h -fsanitize=address

$(NAME_SERVER): $(OBJS_SERVER)
		$(CC) $(CFLAGS) $(SRC_SERVER) -o $(NAME_SERVER) minitalk.h -fsanitize=address

clean:	
			$(RM) $(OBJS_CLIENT) $(OBJS_SERVER)

fclean:	clean
				$(RM) $(NAME_CLIENT) $(NAME_SERVER)
re: fclean all
				
.PHONY: all clean fclean re