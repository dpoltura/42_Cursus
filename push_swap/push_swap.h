/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 10:02:28 by dpoltura          #+#    #+#             */
/*   Updated: 2024/02/21 22:49:17 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_bool
{
	int				boolean;
	int				i;
	int				j;
	long			k;
}					t_bool;

typedef struct s_list
{
	long			nbr;
	int				index;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

void				error(t_list **stack_a, t_bool *boolean, char **argv);
void				error_atoi(t_list *first, t_list **stack_a, t_bool *boolean,
						char **argv);
void				error_no_msg(t_list **stack_a, t_bool *boolean,
						char **argv);
int					is_digit(char *argv);
int					check(t_list **stack_a, char **argv, t_bool *boolean);
void				putstr(char *str, int fd);
void				putnbr(int nbr);
long				ft_atoi(const char *nptr, t_bool *boolean);
void				free_list(t_list **stack);
void				init(t_list **stack, char **argv, t_bool *boolean);
int					swap(t_list **stack, int choice);
int					swap_all(t_list **stack_a, t_list **stack_b);
int					push_a(t_list **stack_b, t_list **stack_a);
int					push_b(t_list **stack_a, t_list **stack_b);
int					rotate(t_list **stack, int choice);
int					rotate_all(t_list **stack_a, t_list **stack_b);
int					reverse_rotate(t_list **stack, int choice);
int					reverse_rotate_all(t_list **stack_a, t_list **stack_b);
int					list_size(t_list **stack);
void				index_list(t_list **stack, int index);
void				index_list_final(t_list **stack_a);
int					check_if_sorted(t_list **stack);
void				sort_two(t_list **stack_a, int choice);
void				sort_three(t_list **stack_a);
void				sort_five(t_list **stack_a, t_list **stack_b);
void				radix_sort(t_list **stack_a, t_list **stack_b);
void				algo(t_list **stack_a, t_list **stack_b);
void				check_double(t_list **stack_a, t_bool *boolean,
						char **argv);
size_t				ft_strlen(const char *s);
char				**ft_split(char const *s, char c);
void				free_argv(char **argv);
void				reset(t_bool *boolean);
#endif