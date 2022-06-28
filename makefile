# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mogonzal <mogonzal@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/27 19:19:58 by mogonzal          #+#    #+#              #
#    Updated: 2022/06/28 18:20:01 by mogonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#___________________________________________________________#

SRC1	=	server.c

SRC2	=	client.c

OBJ1	=	$(SRC1:.c=.o)

OBJ2	=	$(SRC2:.c=.o)

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

LIBFT	=	libft/libft.a

HEADER	=	libft/libft.h

#___________________________________________________________#

all:		server client

libft:		
			$(MAKE) -C ./libft all
			@echo "Building libft"
			
server:		$(OBJ1) $(LIBFT)
			$(CC) $(CFLAGS) $(OBJ1) $(LIBFT) -o server
			@echo "Compiling server"

client:		$(OBJ2) $(LIBFT)
			$(CC) $(CFLAGS) $(OBJ2) $(LIBFT) -o client
			@echo "Compiling client"

clean:		
			$(RM) $(OBJ1) $(OBJ2)
			$(MAKE) -C ./libft clean

fclean:		clean
			$(RM) server client
			$(MAKE) -C ./libft fclean

re:			fclean all
			
.PHONY:		all libft clean fclean re
