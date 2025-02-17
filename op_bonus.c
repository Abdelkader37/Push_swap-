/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqrafi <aqrafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 21:30:32 by aqrafi            #+#    #+#             */
/*   Updated: 2025/02/15 20:28:59 by aqrafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	sa(t_s **stack_a, int n)
{
	int	tmp;

	if (!*stack_a || stack_a)
		return ;
	if ((*stack_a) && (*stack_a)->next)
	{
		tmp = (*stack_a)->data;
		(*stack_a)->data = (*stack_a)->next->data;
		(*stack_a)->next->data = tmp;
	}
	if (n)
		write(1, "sa\n", 3);
}

void	sb(t_s **stack_b, int n)
{
	int	tmp;

	if (!*stack_b || !stack_b)
		return ;
	if ((*stack_b) && (*stack_b)->next)
	{
		tmp = (*stack_b)->data;
		(*stack_b)->data = (*stack_b)->next->data;
		(*stack_b)->next->data = tmp;
	}
	if (n)
		write(1, "sb\n", 3);
}

void	ss(t_s **stack_a, t_s **stack_b, int n)
{
	if (!*stack_a || !stack_a || !stack_b || !*stack_b)
		return ;
	sa(stack_a, 0);
	sb(stack_b, 0);
	if (n)
		write(1, "ss\n", 3);
}

void	pa(t_s **stack_a, t_s **stack_b, int n)
{
	t_s	*tmp;

	if (!stack_b || !*stack_b)
		return ;
	if (n)
		write(1, "pa\n", 3);
	if (!*stack_b || !stack_b)
		return ;
	tmp = remove_top(stack_b);
	stack_add_front(stack_a, tmp);
}

void	pb(t_s **stack_a, t_s **stack_b, int n)
{
	t_s	*tmp;

	if (!stack_a || !*stack_a)
		return ;
	if (n)
		write(1, "pb\n", 3);
	if (!*stack_a || !stack_a)
		return ;
	tmp = remove_top(stack_a);
	stack_add_front(stack_b, tmp);
}
