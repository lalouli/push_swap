# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hlalouli <hlalouli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/02 20:07:25 by hlalouli          #+#    #+#              #
#    Updated: 2022/03/06 15:02:18 by hlalouli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
B_NAME = checker
INC = push_swap.h 
SRCS = algo_sort1.c\
        algo_sort.c\
        check_len.c \
        chek_output.c \
        instructions.c \
        instructions1.c \
        instructions2.c \
        quick_sort.c \
		utils.c \
		utils1.c \
		utils2.c \
		utils3.c \
		opper.c \
		optimiser.c \
		optimiser1.c \
		optimiser2.c \
		push_swap.c \

B_SRCS =  algo_sort1.c\
        algo_sort.c\
        check_len.c \
        chek_output.c \
        instructions.c \
        instructions1.c \
        instructions2.c \
        quick_sort.c \
		utils.c \
		utils1.c \
		utils2.c \
		utils3.c \
		utilis4.c \
		opper.c \
		optimiser.c \
		optimiser1.c \
		optimiser2.c \
		checker_srcs/checker.c \
		checker_srcs/get_next_line.c \
		checker_srcs/get_next_line_utils.c \

B_OBJS = $(B_SRCS:%.c=%.o)
OBJS = $(SRCS:%.c=%.o)
CFLAGS = -Wall -Wextra -Werror
CC = cc

all: $(NAME)
	@ echo "\x1b[32m Project is successfully compiled \x1b[0m"
bonus : $(B_NAME)

$(B_NAME) : $(B_OBJS)
	@$(CC) $(CFLAGS) $(B_OBJS) -o $(B_NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(SRC) $^ -o $(NAME)

%.o:%.c $(INC)
	@$(CC) $(CFLAGS) -c $< -o $@
	@ echo "\x1b[32m Compiling object files \x1b[0m"

clean :
	@$(RM) $(OBJS)
	@$(RM) $(B_OBJS)

fclean : clean
	@$(RM) $(NAME)
	@$(RM) $(B_NAME)
	@ echo "\x1b[31m You deleted all object files in this project \x1b[0m"

re: fclean all
