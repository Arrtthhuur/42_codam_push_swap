# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: abeznik <abeznik@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2022/05/02 14:36:32 by abeznik       #+#    #+#                  #
#    Updated: 2022/05/12 13:48:28 by abeznik       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		:=	checker

# Colours
RED 		:=	\033[1;31m
GRN 		:=	\033[1;32m
BLUE		:=	\033[1;36m
YEL 		:=	\033[0;33m
DEF 		:=	\033[0m

# Directories
INCL_DIR	:=	includes
SRCS_DIR	:=	srcs
OBJ_DIR		:=	objs
VPATH 		:=	$(subst $(space),:,$(shell find srcs -type d))
PRINTF_LIB	:=	libftprintf.a
PRINTF_DIR	:=	./srcs/ft_printf/

# Srcs
SRCS		=	checker.c \
				input_parser.c \
				radix_sort.c \
				exit_message.c \
				ft_split.c \
				ft_strlen.c \
				ft_strncmp.c \
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
				min_max.c \
				is_sorted.c \
				sort_3.c \
				sort_45.c \
				reset_array.c \


OBJS		=	$(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

# Config
CC			:=	gcc
FLAGS		:=	-Wall -Wextra -g -Werror #|| annoying during development

all:		$(NAME)
	
$(NAME):	$(OBJS)
	@echo "$(YEL)\n  Making $(PRINTF_LIB)$(DEF)"
	@make -C $(PRINTF_DIR)
	@echo "$(YEL)\n  Compiling srcs with $(PRINTF_LIB)$(DEF)"
	$(CC) $(OBJS) $(FLAGS) $(PRINTF_DIR)$(PRINTF_LIB) -o $(NAME)
	@echo "$(GRN)\n  Success!$(DEF)"

$(OBJ_DIR)/%.o: $(notdir %.c)
	@mkdir -p $(OBJ_DIR)
	@echo "compiling $(notdir $(basename $@))"
	@$(CC) $(FLAGS) -c $< -I$(INCL_DIR) -o $@

db: all
	lldb $(NAME) -- 0 9 1 8 2 7 3 6 4 5

norm:
	norminette srcs/*.c srcs/utils/*.c srcs/operations/*.c srcs/stack/*.c includes/

clean:
	rm -rf $(OBJ_DIR)

fclean:	clean
	@cd $(PRINTF_DIR) && make fclean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re