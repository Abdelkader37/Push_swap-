/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqrafi <aqrafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:54:39 by aqrafi            #+#    #+#             */
/*   Updated: 2025/02/24 21:30:58 by aqrafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

long	ft_atoi(const char *str)
{
	int		i;
	long	num;
	int		sign;

	i = 0;
	sign = 1;
	num = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign = -(sign);
		i++;
		if (str[i] == '+' && str[i] == '-')
			return (0);
	}
	if (str[i] == '+')
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (atoi_err(num * sign, &str[i]));
}

void	freestr(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
