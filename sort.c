/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqrafi <aqrafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:50:08 by aqrafi            #+#    #+#             */
/*   Updated: 2025/02/11 20:35:02 by aqrafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	sort(t_s **stack_a, t_s **stack_b)
{
	int	len;
	int	max_r;

	len = t_s_len(*stack_a);
	max_r = len * 0.048 + 10;
	indexing(*stack_a);
	push_to_b(stack_a, stack_b, max_r);
	push_to_a(stack_a, stack_b, len - 1);
}

int	t_s_len(t_s *stack)
{
	int	len;

	if (!stack)
		return (0);
	len = 0;
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

void	indexing(t_s *stack_a)
{
	int	index;
	t_s	*head;
	t_s	*curent;

	head = stack_a;
	curent = stack_a;
	while (head)
	{
		index = 0;
		curent = stack_a;
		while (curent)
		{
			if (head->data > curent->data)
				index++;
			curent = curent->next;
		}
		head->index = index;
		head = head->next;
	}
}

void	push_to_b(t_s **stack_a, t_s **stack_b, int max_r)
{
	int	min_r;

	min_r = 0;
	if (!stack_a || !*stack_a)
		return ;
	while (*stack_a)
	{
		if ((*stack_a)->index <= max_r)
		{
			pb(stack_a, stack_b, 1);
			if ((*stack_b)->index < min_r)
				rb(stack_b, 1);
			min_r++;
			max_r++;
		}
		else
			ra(stack_a, 1);
	}
}

void	push_to_a(t_s **stack_a, t_s **stack_b, int max)
{
	int	pos;
	int	len;

	if (!stack_b || !*stack_b)
		return ;
	while (*stack_b)
	{
		len = t_s_len(*stack_b);
		pos = max_pos(*stack_b, max);
		if (pos == 0)
		{
			pa(stack_a, stack_b, 1);
			max--;
		}
		else if (pos > len / 2)
			rrb(stack_b, 1);
		else
			rb(stack_b, 1);
	}
}
