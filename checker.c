/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqrafi <aqrafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 22:35:52 by aqrafi            #+#    #+#             */
/*   Updated: 2025/02/15 20:44:04 by aqrafi           ###   ########.fr       */
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
			test(&stack_a, &stack_b);
		return (stackclear(&stack_a), stackclear(&stack_b), 0);
	}
}

void	test(t_s **stack_a, t_s **stack_b)
{
	char	*str;

	while (1)
	{
		str = get_next_line(0);
		if (!str)
			break ;
		exc(str, stack_a, stack_b);
		free(str);
	}
	if (check_if_sort(*stack_a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

void	exc(char *str, t_s **stack_a, t_s **stack_b)
{
	 if (str_cmp(str, "sa\n"))
		sa(stack_a, 0);
	else if (str_cmp(str, "sb\n"))
		sb(stack_b, 0);
	else if (str_cmp(str, "ss\n"))
		ss(stack_a, stack_b, 0);
	else if (str_cmp(str, "ra\n"))
		ra(stack_a, 0);
	else if (str_cmp(str, "rb\n"))
		rb(stack_b, 0);
	else if (str_cmp(str, "rr\n"))
		rr(stack_a, stack_a, 0);
	else if (str_cmp(str, "rra\n"))
		rra(stack_a, 0);
	else if (str_cmp(str, "rrb\n"))
		rrb(stack_b, 0);
	else if (str_cmp(str, "rrr\n"))
		rrr(stack_a, stack_b, 0);
	else if (str_cmp(str, "pa\n"))
		pa(stack_a, stack_b, 0);
	else if (str_cmp(str, "pb\n"))
		pb(stack_a, stack_b, 0);
	else
		ft_exit();
}

int	str_cmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

void ft_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}