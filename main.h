/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqrafi <aqrafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:47:19 by aqrafi            #+#    #+#             */
/*   Updated: 2025/02/24 21:14:08 by aqrafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "get_next_line.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				data;
	int				index;
	struct s_stack	*next;

}					t_s;

char				**ft_split(char const *s, char c);
int					ft_isdigit(int c);
long				ft_atoi(const char *str);
int					check_digit(char **str);
t_s					*new_node(int content);
void				ss(t_s **stack_a, t_s **stack_b, int n);
void				stack_add_back(t_s **stack, t_s *new);
void				stack_add_front(t_s **stack, t_s *new);
void				pb(t_s **stack_a, t_s **stack_b, int n);
void				add_to_stack(t_s **stack, char **str);
t_s					*remove_bot(t_s **stack);
t_s					*remove_top(t_s **stack);
void				stackclear(t_s **stack);
int					check_dup(t_s *stack);
void				freestr(char **str);
void				rrb(t_s **stack_b, int n);
void				rra(t_s **stack_a, int n);
void				rrr(t_s **stack_a, t_s **stack_b, int n);
void				rr(t_s **stack_a, t_s **stack_b, int n);
void				rb(t_s **stack_b, int n);
int					str_cmp(char *s1, char *s2);
void				ra(t_s **stack_a, int n);
void				pa(t_s **stack_a, t_s **stack_b, int n);
void				sb(t_s **stack_b, int n);
void				sa(t_s **stack_a, int n);
void				sort(t_s **stack_a, t_s **stack_b);
int					t_s_len(t_s *stack);
void				indexing(t_s *stack_a);
int					max_pos(t_s *stack, int max);
int					check_if_sort(t_s *stack);
void				push_to_a(t_s **stack_a, t_s **stack_b, int max);
void				sort_five(t_s **stack_a, t_s **stack_b);
void				sort_three(t_s **stack_a);
void				push_to_b(t_s **a, t_s **b, int range_size);
void				test(t_s **stack_a, t_s **stack_b);
void				exc(char *str, t_s **stack_a, t_s **stack_b);
void				ft_exit(char *str, t_s **stack_a, t_s **stack_b);
int					error_h(void);
long				atoi_err(long n, const char *str);

#endif