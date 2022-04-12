/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/01 13:58:30 by abeznik       #+#    #+#                 */
/*   Updated: 2022/04/12 15:57:58 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h> // EXIT_
# include <stddef.h> // size_t

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

// Main functions.
int			main(int argc, char **argv);
void		input_parser(char **argv, int argc, t_stack **stack);

// Algorithm functions.
void		pancake_sort(int *arr, int n);
void		print_array(int arr[], int n);

// Operation functions.
void		swap(t_stack **stack);
void		rotate(t_stack **stack);
void		push(t_stack **src, t_stack **dest);

// Stack functions.
void		stack_addfront(t_stack **s, int value);
void		stack_print(t_stack *a, char stack);

// Util functions.
size_t		ft_strlen(const char *s);
char		**ft_split(char const *s, char c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			ft_isdigit(int c);
int			ft_isspace(int c);
long long	ft_atoll(const char *str);
int			ft_atoi(const char *str);
int			*convert_int(char **argv, int len);

// Exit succes or error message.
int			error_msg(char *msg);
int			success_msg(char *msg);
void		error_exit(void);

#endif