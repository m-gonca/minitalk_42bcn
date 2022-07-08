# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mogonzal <mogonzal@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/27 19:19:58 by mogonzal          #+#    #+#              #
#    Updated: 2022/06/30 13:38:31 by mogonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#___________________________________________________________#

SRC1	=	server.c

SRC2	=	client.c

BNS_S1	=	server_bonus.c

BNS_S2	=	client_bonus.c

OBJ1	=	$(SRC1:.c=.o)

OBJ2	=	$(SRC2:.c=.o)

BNS_O1	=	$(BNS_S1:.c=.o)

BNS_O2	=	$(BNS_S2:.c=.o)

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

LIBFT	=	libft/libft.a

HEADER	=	libft/libft.h

#___________________________________________________________#

all:		libft server client

libft:		
			@$(MAKE) -C ./libft all
			
server:		$(OBJ1) $(LIBFT)
			@$(CC) $(CFLAGS) $(OBJ1) $(LIBFT) -o server
			@echo "Compiling server"

client:		$(OBJ2) $(LIBFT)
			@$(CC) $(CFLAGS) $(OBJ2) $(LIBFT) -o client
			@echo "Compiling client"

bonus:		libft $(BNS_O1) $(BNS_O2) $(LIBFT)
			@$(CC) $(CFLAGS) $(BNS_O1) $(LIBFT) -o server_bonus
			@echo "Compiling server_bonus"
			@$(CC) $(CFLAGS) $(BNS_O2) $(LIBFT) -o client_bonus
			@echo "Compiling client_bonus"
			
clean:		
			$(RM) $(OBJ1) $(OBJ2)
			$(RM) $(BNS_O1) $(BNS_O2)
			$(MAKE) -C ./libft clean
			@echo "Clean done"

fclean:		clean
			$(RM) server client
			$(RM) server_bonus client_bonus
			$(MAKE) -C ./libft fclean
			@echo "FClean done"

re:			fclean all
			
.PHONY:		all libft clean fclean re
