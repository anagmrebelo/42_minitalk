# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anarebelo <anarebelo@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/21 22:39:55 by anarebelo         #+#    #+#              #
#    Updated: 2023/02/22 01:42:54 by anarebelo        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME
# **************************************************************************** #
NAME_S			= server
NAME_C			= client
NAME_S_BONUS	= server_bonus
NAME_C_BONUS	= client_bonus

# FILES
# **************************************************************************** #
FILES_S 		= minitalk_server.c
FILES_S_BONUS	= minitalk_server_bonus.c
FILES_C 		= minitalk_client.c
FILES_C_BONUS	= minitalk_client_bonus.c

OBJS_S	 		=${addprefix ${OBJS_DIR}, ${FILES_S:.c=.o}}
OBJS_S_BONUS 	=${addprefix ${OBJS_DIR}, ${FILES_S_BONUS:.c=.o}}
OBJS_C 			=${addprefix ${OBJS_DIR}, ${FILES_C:.c=.o}}
OBJS_C_BONUS	=${addprefix ${OBJS_DIR}, ${FILES_C_BONUS:.c=.o}}

DEPS_S			=${addprefix ${OBJS_DIR}, ${FILES_S:.c=.d}}
DEPS_C			=${addprefix ${OBJS_DIR}, ${FILES_C:.c=.d}}
DEPS_S_BONUS	=${addprefix ${OBJS_DIR}, ${FILES_S_BONUS:.c=.d}}
DEPS_C_BONUS	=${addprefix ${OBJS_DIR}, ${FILES_C_BONUS:.c=.d}}

# DIRECTORY
# **************************************************************************** #
OBJS_DIR			= objs/
SRCS_DIR			= srcs/
PRINTF_DIR			= ftprintf/

# LIBRARIES
# **************************************************************************** #
INCLUDE				= -I inc -I ${PRINTF_DIR}inc -I ${PRINTF_DIR}libft/inc
LIB_EXEC			= ${PRINTF_DIR}libftprintf.a

# RULES
# **************************************************************************** #
LINK				= gcc
CC					= gcc -c
DEPFLAGS			= -MMD -MP
CFLAGS				= -Wall -Wextra -Werror 
RM					= rm -rf

# RULES
# **************************************************************************** #
all:		make_printf ${NAME_S} ${NAME_C} 

$(OBJS_DIR)%.o:	$(SRCS_DIR)%.c
			@mkdir -p $(dir $@)
			$(CC) $(CFLAGS) $(DEPFLAGS) $(INCLUDE) $< -o $@

make_printf:
			@$(MAKE) -C ${PRINTF_DIR}

$(NAME_C):	${OBJS_C}
			${LINK} ${CFLAGS} ${OBJS_C} -o ${NAME_C} ${LIB_EXEC}

$(NAME_S):	${OBJS_S}
			${LINK} ${CFLAGS} ${OBJS_S} -o ${NAME_S} ${LIB_EXEC}

bonus:		make_printf ${NAME_C_BONUS} ${NAME_S_BONUS}

${NAME_C_BONUS}: ${OBJS_C_BONUS} 
			@${LINK} ${CFLAGS} ${OBJS_C_BONUS} -o ${NAME_C} ${LIB_EXEC}

${NAME_S_BONUS}: ${OBJS_S_BONUS}	
			@${LINK} ${CFLAGS} ${OBJS_S_BONUS} -o ${NAME_S} ${LIB_EXEC}

clean:	
			@${RM} ${OBJS_DIR}
			@$(MAKE) -C ${PRINTF_DIR} clean

fclean:		clean
			@${RM} $(NAME_C) $(NAME_S)
			@${RM} ${NAME_C_BONUS} ${NAME_S_BONUS}
			@$(MAKE) -C ${PRINTF_DIR} fclean

re:		fclean all

-include ${DEPS_S}
-include ${DEPS_C}
-include ${DEPS_S_BONUS}
-include ${DEPS_C_BONUS}

.PHONY:		all clean fclean re
