/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqrafi <aqrafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 20:53:34 by aqrafi            #+#    #+#             */
/*   Updated: 2025/02/24 20:56:24 by aqrafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

int	check_digit(char **str)
{
	int	i;
	int	j;

	i = 0;
	if (!str[i] || str[i][0] == '\0')
		return (error_h());
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (!ft_isdigit(str[i][j]) && !((str[i][j] == '-'
						|| str[i][j] == '+') && ft_isdigit(str[i][j + 1])))
				return (error_h());
			j++;
		}
		i++;
	}
	return (1);
}

int	check_dup(t_s *stack)
{
	t_s	*tmp;

	tmp = stack;
	if (!stack)
		return (0);
	while (stack)
	{
		tmp = stack;
		while (tmp->next)
		{
			tmp = tmp->next;
			if (stack->data == tmp->data)
			{
				write(2, "Error\n", 6);
				return (0);
			}
		}
		stack = stack->next;
	}
	return (1);
}

int	max_pos(t_s *stack, int max)
{
	int	pos;

	if (!stack)
		return (-1);
	pos = 0;
	while (stack)
	{
		if (stack->index == max)
			return (pos);
		stack = stack->next;
		pos++;
	}
	return (-1);
}

int	check_if_sort(t_s *stack)
{
	while (stack->next)
	{
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}
