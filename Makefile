# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: abeznik <abeznik@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2022/02/01 13:52:46 by abeznik       #+#    #+#                  #
#    Updated: 2022/05/06 17:39:49 by abeznik       ########   odam.nl          #
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
LIBFTPRINTF	:=	libftprintf.a
PRINTF_DIR	:=	./srcs/ft_printf/

BONUS 		:=	0

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

ifeq ($(BONUS),0)
	MAKE_BONUS = 
	OBJ_FILES = $(OBJS)
else
	MAKE_BONUS = bonus
	OBJ_FILES = $(OBJS)
endif

# Config
CC			:=	gcc
FLAGS		:=	-Wall -Wextra -g #-Werror || annoying during development

all:		makedir $(NAME) $(MAKE_BONUS)
			@echo "$(GRN)\n--- MAKEFILE DONE ------------ \n$(DEF)"

$(NAME): $(OBJ_FILES)
		@echo "$(GRN)\n - Compiling push_swap Executable --- $(DEF)"
		gcc $^ $(FLAGS) $(PRINTF_DIR)${LIBFTPRINTF} -o $(NAME)

makedir:
		@echo "$(GRN)\n --- START MAKEFILE ------------ \n$(DEF)"
		@echo "$(GRN) Making obj_dir Directory $(DEF)"
		mkdir -p $(OBJ_DIR)/
		@echo "$(GRN)\n Making libftprintf.a Library $(DEF)"
		make -C $(PRINTF_DIR)
		@echo "$(GRN)\n Compiling .c Files $(DEF)"

$(OBJ_DIR)/%.o: $(notdir %.c)
		gcc -g $(FLAGS) -c $< -o $@

run: all
	./$(NAME)

drun: all
	lldb $(NAME) -- 588 1 8 600

norm:
	norminette srcs/*.c srcs/utils/*.c srcs/operations/*.c srcs/stack/*.c includes/

tmine: all
	./tester.sh m
	
teval: all
	./tester.sh

tbonus: all
	./tester.sh c

ttest: all
	./tester.sh t

bonus:	all
		@echo "$(YEL)\n- Go to Make Bonus: [$(BONNUS)] (System: $(UNAME_S)) --- $(WHITE)"
		BONNUS=1
		make -C ./mychecker_bonus

clean:
	@rm -rf $(OBJ_DIR)
	@rm -rf $(NAME)

fclean:	clean
	cd srcs/ft_printf && make fclean
	rm -f $(NAME)
	cd ./checker_bonus && make fclean

re:	fclean all

.PHONY:	all clean fclean re