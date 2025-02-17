/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op2_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqrafi <aqrafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:08:37 by aqrafi            #+#    #+#             */
/*   Updated: 2025/02/15 21:19:29 by aqrafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ra(t_s **stack_a, int n)
{
	t_s	*tmp;

	if (!stack_a || !*stack_a)
		return ;
	if (n)
		write(1, "ra\n", 3);
	tmp = remove_top(stack_a);
	stack_add_back(stack_a, tmp);
}

void	rb(t_s **stack_b, int n)
{
	t_s	*tmp;

	if (!*stack_b || !stack_b)
		return ;
	if (n)
		write(1, "rb\n", 3);
	tmp = remove_top(stack_b);
	stack_add_back(stack_b, tmp);
}

void	rr(t_s **stack_a, t_s **stack_b, int n)
{
	if (!*stack_a || !stack_a || !stack_b || !*stack_b)
		return ;
	ra(stack_a, 0);
	rb(stack_b, 0);
	if (n)
		write(1, "rr\n", 3);
}

void	rra(t_s **stack_a, int n)
{
	t_s	*tmp;

	if (!*stack_a || !stack_a)
		return ;
	if (n)
		write(1, "rra\n", 4);
	tmp = remove_bot(stack_a);
	stack_add_front(stack_a, tmp);
}

void	rrb(t_s **stack_b, int n)
{
	t_s	*tmp;

	if (!*stack_b || !stack_b)
		return ;
	if (n)
		write(1, "rrb\n", 4);
	tmp = remove_bot(stack_b);
	stack_add_front(stack_b, tmp);
}
