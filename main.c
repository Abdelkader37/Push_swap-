/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqrafi <aqrafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 21:30:18 by aqrafi            #+#    #+#             */
/*   Updated: 2025/02/11 20:37:11 by aqrafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int ac, char *av[])
{
	int		i;
	char	**str;
	t_s		*stack_a;
	t_s		*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	i = 1;
	if (ac >= 2)
	{
		while (av[i])
		{
			str = ft_split(av[i], ' ');
			if (check_digit(str))
				add_to_stack(&stack_a, str);
			else
				return (freestr(str), stackclear(&stack_a), 0);
			i++;
		}
		if (!check_dup(stack_a))
			return (stackclear(&stack_a), 0);
		if (!check_if_sort(stack_a))
			sort(&stack_a, &stack_b);
	}
}
