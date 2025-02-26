/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqrafi <aqrafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 21:29:41 by aqrafi            #+#    #+#             */
/*   Updated: 2025/02/24 21:15:37 by aqrafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_s	*new_node(int content)
{
	t_s	*new;

	new = malloc(sizeof(t_s));
	if (!new)
		return (NULL);
	new->data = (content);
	new->next = NULL;
	return (new);
}

void	stack_add_front(t_s **stack, t_s *new)
{
	if (!new || !stack)
		return ;
	new->next = *stack;
	*stack = new;
}

void	stack_add_back(t_s **stack, t_s *new)
{
	t_s	*curent;

	if (!new || !stack)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	curent = *stack;
	while (curent->next)
		curent = curent->next;
	curent->next = new;
}

void	add_to_stack(t_s **stack, char **str)
{
	int		i;
	long	j;
	t_s		*new;

	i = 0;
	if (!str || !*str)
		return ;
	while (str[i])
	{
		j = ft_atoi(str[i]);
		if (j > INT_MAX || j < INT_MIN)
		{
			write(2, "Error\n", 6);
			stackclear(stack);
			freestr(str);
			exit(1);
		}
		new = new_node(j);
		if (!new)
			return (stackclear(stack), freestr(str));
		stack_add_back(stack, new);
		i++;
	}
	freestr(str);
}

void	stackclear(t_s **stack)
{
	t_s	*current;

	if (!stack)
		return ;
	if (*stack)
	{
		while (*stack)
		{
			current = *stack;
			*stack = (*stack)->next;
			free(current);
		}
		*stack = NULL;
	}
}
