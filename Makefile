# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsoubaig <bsoubaig@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/29 09:27:04 by bsoubaig          #+#    #+#              #
#    Updated: 2023/01/10 12:06:03 by bsoubaig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors constants
PURPLE		= \033[38;5;141m
GREEN		= \033[38;5;46m
RED			= \033[0;31m
GREY		= \033[38;5;240m
RESET		= \033[0m
BOLD		= \033[1m

NAME				= minitalk
CLIENT				= client
SERVER				= server

LIBFT_PRINTF		= ft_printf/libftprintf.a
LIBFT_PRINTF_DIR	= ft_printf

SRC_DIR				= ./srcs/
SRC_SRV				= ft_server.c
SRC_CLI				= ft_client.c
SRCS				= ft_utils.c

OBJ_DIR				= ./objs/
OBJ_SRV				= ${addprefix ${OBJ_DIR}, ${SRC_SRV:.c=.o}}
OBJ_CLI				= ${addprefix ${OBJ_DIR}, ${SRC_CLI:.c=.o}}
OBJS				= ${addprefix ${OBJ_DIR}, ${SRCS:.c=.o}}

RM					= rm -rf
CC					= gcc
CFLAGS				= -Wall -Wextra -Werror

${OBJ_DIR}%.o:	${SRC_DIR}%.c
	@${CC} ${CFLAGS} -I${SRC_DIR} -c $< -o $@

all:			${SERVER} ${CLIENT}

${SERVER}:		${LIBFT_PRINTF} ${OBJS} ${OBJ_SRV}
	@echo "${RESET}${GREEN}»${RESET} [${PURPLE}${BOLD}${NAME}${RESET}]: Objects were made ${GREEN}successfully${RESET}.${GREY}"
	@echo "${RESET}${GREEN}»${RESET} [${PURPLE}${BOLD}${NAME}${RESET}]: Compiling project...${GREY}"
	@${CC} ${CFLAGS} ${OBJS} ${OBJ_SRV} -o ${SERVER} ${LIBFT_PRINTF}
	@echo "${RESET}${GREY}────────────────────────────────────────────────────────────────────────────"
	@echo "${RESET}${GREEN}»${RESET} [${PURPLE}${BOLD}${NAME}${RESET}]: ${RED}Server${RESET} compiled ${GREEN}successfully${RESET}.${GREY}"
	@echo "${RESET}${GREY}────────────────────────────────────────────────────────────────────────────"

${CLIENT}:		${LIBFT_PRINTF} ${OBJS} ${OBJ_CLI}
	@echo "${RESET}${GREEN}»${RESET} [${PURPLE}${BOLD}${NAME}${RESET}]: Objects were made ${GREEN}successfully${RESET}.${GREY}"
	@echo "${RESET}${GREEN}»${RESET} [${PURPLE}${BOLD}${NAME}${RESET}]: Compiling project...${GREY}"
	@${CC} ${CFLAGS} ${OBJS} ${OBJ_CLI} -o ${CLIENT} ${LIBFT_PRINTF}
	@echo "${RESET}${GREY}────────────────────────────────────────────────────────────────────────────"
	@echo "${RESET}${GREEN}»${RESET} [${PURPLE}${BOLD}${NAME}${RESET}]: ${RED}Client${RESET} compiled ${GREEN}successfully${RESET}.${GREY}"
	@echo "${RESET}${GREY}────────────────────────────────────────────────────────────────────────────"

${OBJS}:		| ${OBJ_DIR}

${OBJ_SRV}:		| ${OBJ_DIR}

${OBJ_CLI}:		| ${OBJ_DIR}

${OBJ_DIR}:
	@echo "${RESET}${GREEN}»${RESET} [${PURPLE}${BOLD}${NAME}${RESET}]: Creating objects directory...${GREY}"
	@mkdir ${OBJ_DIR}

${LIBFT_PRINTF}:
	@make -C ${LIBFT_PRINTF_DIR}

clean:
	@make clean -C ${LIBFT_PRINTF_DIR}
	@${RM} ${OBJ_DIR}
	@echo "${RESET}${GREEN}»${RESET} [${PURPLE}${BOLD}${NAME}${RESET}]: Objects were cleaned ${GREEN}successfully${RESET}.${GREY}"

fclean:	clean
	@make fclean -C ${LIBFT_PRINTF_DIR}
	@${RM} ${SERVER} ${CLIENT} ${SRCS}
	@echo "${RESET}${GREY}────────────────────────────────────────────────────────────────────────────"
	@echo "${RESET}${GREEN}»${RESET} [${PURPLE}${BOLD}${NAME}${RESET}]: Project cleaned ${GREEN}successfully${RESET}.${GREY}"
	@echo "${RESET}${GREY}────────────────────────────────────────────────────────────────────────────"

re:	fclean all

.SILENT: all clean fclean re 
.PHONY:	all clean fclean re
