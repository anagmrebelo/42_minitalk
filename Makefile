NAME_S		= server
NAME_C		= client

SRCS_S 		= minitalk_server.c
SRCS_S_BONUS	= minitalk_server_bonus.c
SRCS_C 		= minitalk_client.c
SRCS_C_BONUS	= minitalk_client_bonus.c

OBJS_S	 	= ${SRCS_S:.c=.o}
OBJS_S_BONUS 	= ${SRCS_S:.c=.o}
OBJS_C 		= ${SRCS_C:.c=.o}
OBJS_C_BONUS	= ${SRCS_C:.c=.o}

INCLUDE = includes/minitalk.h

CC 	= gcc
CFLAGS	= -Wall -Werror -Wextra
RM	= rm -f

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:		${NAME_S} ${NAME_C} 

$(NAME_C):	${OBJS_C}
			$(MAKE) -C ./ftprintf all
			@${CC} ${CFLAGS} ${SRCS_C} -o ${NAME_C} ftprintf/libftprintf.a

$(NAME_S):	${OBJS_S}
			$(MAKE) -C ./ftprintf all
			@${CC} ${CFLAGS} ${SRCS_S} -o ${NAME_S} ftprintf/libftprintf.a

bonus:		${OBJS_C_BONUS} ${OBJS_S_BONUS}	
			@${RM} $(NAME_C) $(NAME_S)
			$(MAKE) -C ./ftprintf all
			@${CC} ${CFLAGS} ${SRCS_C_BONUS} -o ${NAME_C} ftprintf/libftprintf.a
			@${CC} ${CFLAGS} ${SRCS_S_BONUS} -o ${NAME_S} ftprintf/libftprintf.a
clean:	
			@${RM} ${OBJS_S} ${OBJS_C} ${OBJS_S_BONUS} ${OBJS_C_BONUS}
			$(MAKE) -C ./ftprintf clean

fclean:		clean
			@${RM} $(NAME_C) $(NAME_S)
			$(MAKE) -C ./ftprintf fclean

re:		fclean all

.PHONY:		all clean fclean re
