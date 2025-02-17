/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqrafi <aqrafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:52:01 by aqrafi            #+#    #+#             */
/*   Updated: 2025/02/15 20:32:26 by aqrafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_s	*remove_top(t_s **stack)
{
	t_s	*tmp;

	if (!stack || !*stack)
		return (NULL);
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = NULL;
	return (tmp);
}

t_s	*remove_bot(t_s **stack)
{
	t_s	*tmp;
	t_s	*head;

	if (!stack || !*stack || !((*stack)->next))
		return (NULL);
	tmp = *stack;
	head = NULL;
	while (tmp->next)
	{
		head = tmp;
		tmp = tmp->next;
	}
	head->next = NULL;
	return (tmp);
}

void	rrr(t_s **stack_a, t_s **stack_b, int n)
{
	if (!*stack_a || !stack_a || !stack_b || !*stack_b)
		return ;
	rra(stack_a, 0);
	rrb(stack_b, 0);
	if (n)
		write(1, "rrr\n", 4);
}
