# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: abeznik <abeznik@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2021/10/03 15:23:47 by abeznik       #+#    #+#                  #
#    Updated: 2022/04/13 13:04:20 by abeznik       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SOURCES	=	ft_printf.c \
			pf_conversions.c \
			pf_hex_conv.c \
			pf_hexlong_conv.c \
			pf_format_print.c \
			pf_u_print.c \
			pf_utoa.c \

SRC_DIR	=	srcs

UTILS	=	ft_intlen.c \
			ft_putchar.c \
			ft_putnbr.c \
			ft_putstr.c \
			ft_strlen.c \
			ft_tolower.c \

UTL_DIR	=	utils

OBJ_DIR	=	obj

HEADER	=	includes

SRCS 	=	$(addprefix $(SRC_DIR)/,$(SOURCES))
OBJ_S 	=	$(patsubst %, $(OBJ_DIR)/srcs/%, $(SOURCES:.c=.o))

UTLS	=	$(addprefix $(UTL_DIR)/,$(UTILS))
OBJ_U 	=	$(patsubst %, $(OBJ_DIR)/utils/%, $(UTILS:.c=.o))

CC		=	gcc
RM		=	rm -f
FLAGS	=	-Werror -Wextra -Wall

all:		$(NAME)

$(NAME):	$(OBJ_S) $(OBJ_U)
	@echo "Creating archive $(NAME)"
	@ar cr $(NAME) $(OBJ_S) $(OBJ_U)

$(OBJ_DIR)/srcs/%.o: $(SRC_DIR)/%.c
	@mkdir -p obj/srcs
	@echo "compiling $(notdir $(basename $@))"
	@$(CC) -c $(FLAGS) -I $(HEADER) -o $@ $<

$(OBJ_DIR)/utils/%.o: $(UTL_DIR)/%.c
	@mkdir -p obj/utils
	@echo "compiling $(notdir $(basename $@))"
	@$(CC) -c $(FLAGS) -I $(HEADER) -o $@ $<

clean:
	$(RM) $(OBJ_S) $(OBJ_U)
	rm -rf $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: fclean re all clean