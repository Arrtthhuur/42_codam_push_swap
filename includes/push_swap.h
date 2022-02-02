/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/01 13:58:30 by abeznik       #+#    #+#                 */
/*   Updated: 2022/02/02 16:09:35 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h> // EXIT_
# include <stddef.h> // size_t

typedef struct s_stack
{
	int				elem;
	int				index;
	struct s_stack	*next;
}	t_stack;

int		main(int argc, char **argv);

// Algorithm functions.
void pancake_sort(int* arr, int n);
void print_array(int arr[], int n);

// Util functions.
size_t	ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);

// Exit succes or error message.
int		error_msg(char *msg);
int		success_msg(char *msg);

#endif