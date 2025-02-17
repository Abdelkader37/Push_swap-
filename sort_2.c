/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqrafi <aqrafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:31:19 by aqrafi            #+#    #+#             */
/*   Updated: 2025/02/17 18:11:35 by aqrafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	sort_three(t_s **stack_a)
{
	if ((*stack_a)->data > (*stack_a)->next->data)
		sa(stack_a, 1);
	if ((*stack_a)->next->data > (*stack_a)->next->next->data)
		rra(stack_a, 1);
	if ((*stack_a)->data > (*stack_a)->next->data)
		sa(stack_a, 1);
}

void	sort_five(t_s **stack_a, t_s **stack_b)
{
	if ((*stack_a)->next->next->next->next->index == 0)
		rra(stack_a, 1);
	while ((*stack_a)->index != 0)
		ra(stack_a, 1);
	pb(stack_a, stack_b, 1);
	while ((*stack_a)->index != 1)
		ra(stack_a, 1);
	pb(stack_a, stack_b, 1);
	sort_three(stack_a);
	pa(stack_a, stack_b, 1);
	pa(stack_a, stack_b, 1);
}
