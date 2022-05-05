/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/02 14:29:42 by abeznik       #+#    #+#                 */
/*   Updated: 2022/05/05 14:52:48 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../../srcs/ft_printf/includes/libftprintf.h"

# include <stdlib.h> // EXIT_
# include <stddef.h> // size_t

# include <sys/types.h> // read
# include <sys/uio.h> // read
# include <unistd.h> // read

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# define STACK_A 'a'
# define STACK_B 'b'

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

// Main functions.
int			main(int argc, char **argv);
void		input_parser(char **argv, int argc, t_stack **stack);

// Algorithm functions.
void		sort_3(t_stack **stack, int min, int max);
void		sort_45(t_stack **a, t_stack **b);
void		radix_sort(t_stack **a, t_stack **b);

// Operation functions.
void		swap(t_stack **stack);
void		rotate(t_stack **stack);
void		rev_rotate(t_stack **stack);
void		push(t_stack **dst, t_stack **src);

// Stack functions.
void		stack_addfront(t_stack **s, int value, int index);
void		stack_print(t_stack *s, char stack_name);
int			stack_len(t_stack **stack);
int			is_sorted(t_stack **stack);
int			get_min(t_stack **stack);
int			get_max(t_stack **stack);

// Util functions.
size_t		ft_strlen(const char *s);
char		**ft_split(char const *s, char c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_isdigit(int c);
int			ft_isspace(int c);
long long	ft_atoll(const char *str);
int			ft_atoi(const char *str);
int			*convert_int(char **argv, int len);
void		reset(char *op);

// Exit succes or error message.
int			error_msg(char *msg);
int			success_msg(char *msg);
void		error_exit(void);
int			success_exit(void);
int			failure_exit(void);

#endif