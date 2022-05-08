# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: abeznik <abeznik@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2022/02/01 13:52:46 by abeznik       #+#    #+#                  #
#    Updated: 2022/05/07 22:26:14 by abeznik       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		:=	push_swap

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
SRCS		=	main.c \
				input_parser.c \
				radix_sort.c \
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
				stack_index.c \
				swap.c \
				rotate.c \
				push.c \
				min_max.c \
				is_sorted.c \
				sort_3.c \
				sort_45.c \

OBJS		=	$(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

# Bonus
BONUS 		:=	0

ifeq ($(BONUS),0)
	MAKE_BONUS = 
	OBJ_FILES = $(OBJS)
else
	MAKE_BONUS = bonus
	OBJ_FILES = $(OBJS)
endif

# Config
CC			:=	cc
FLAGS		:=	-Wall -Wextra -g #-Werror #|| annoying during development

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
	lldb $(NAME) -- 588 1 8 600

norm:
	norminette srcs/* checker_bonus/srcs/*

tmine: all
	./tester.sh m
	
teval: all
	./tester.sh

tbonus: all
	./tester.sh c

ttest: all
	./tester.sh t

bonus:	all
	make -C ./checker_bonus

clean:
	@rm -rf $(OBJ_DIR)
	@rm -rf $(NAME)

fclean:	clean
	@cd $(PRINTF_DIR) && make fclean
	@cd ./checker_bonus && make fclean
	rm -f $(NAME)
	rm tmp

re:	fclean all

.PHONY:	all clean fclean re