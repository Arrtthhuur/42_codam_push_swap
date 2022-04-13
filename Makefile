# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: abeznik <abeznik@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2022/02/01 13:52:46 by abeznik       #+#    #+#                  #
#    Updated: 2022/04/13 16:28:23 by abeznik       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		:=	push_swap

# Directories
INCL_DIR	:=	includes
SRCS_DIR	:=	srcs
OBJ_DIR		:=	objs
VPATH 		:=	$(subst $(space),:,$(shell find srcs -type d))
LIBFTPRINTF	:=	libftprintf.a

# Srcs
SRCS		=	main.c \
				input_parser.c \
				radix_sort.c \
				pancake.c \
				exit_message.c \
				ft_split.c \
				ft_strlen.c \
				ft_substr.c \
				ft_isdigit.c \
				ft_atoi.c \
				ft_atoll.c \
				ft_isspace.c \
				stack_addfront.c \
				stack_len.c \
				stack_print.c \
				swap.c \
				rotate.c \
				push.c \
				get_max.c \

OBJS		=	$(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

# Config
CC			:=	gcc
FLAGS		:=	-Wall -Wextra -g #-Werror || annoying during development

all:		$(NAME)

$(NAME):	$(OBJS)
	@echo "Making libftprintf.a"
	@make -C $(SRCS_DIR)/ft_printf
	@echo "Copying libftprintf.a to push_swap dir"
	@cp $(SRCS_DIR)/ft_printf/$(LIBFTPRINTF) .
	@echo "Compiling srcs with newly created archive"
	@$(CC) $(LIBFTPRINTF) $(OBJS) $(FLAGS) -o $(NAME)
	@echo success!

$(OBJ_DIR)/%.o: $(notdir %.c)
	@mkdir -p $(OBJ_DIR)
	@echo "compiling $(notdir $(basename $@))"
	@$(CC) $(FLAGS) -c $< -I$(INCL_DIR) -o $@

run: all
	./$(NAME)

drun: all
	lldb $(NAME) -- 1 2 5 4

norm:
	norminette srcs/*.c srcs/utils/*.c srcs/operations/*.c srcs/stack/*.c includes/

test:
	@$(MAKE) -C unit-tests

local:
	TEST=1
	@echo $(SRCS)

echo:
	@$(MAKE) -C unit-tests echo

clean:
	@rm -rf $(OBJ_DIR)
	@rm -rf $(NAME)
	make fclean -C $(SRCS_DIR)/ft_printf

fclean:	clean
	@rm -f $(NAME)
	@rm libftprintf.a

re:	fclean all

.PHONY:	all clean fclean re