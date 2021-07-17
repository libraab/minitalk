/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 18:06:08 by abouhlel          #+#    #+#             */
/*   Updated: 2021/07/17 18:06:10 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/utils.h"

int	ft_atoi(const char *str)
{
	long	sign;
	long	neg;
	long	a;
	long	i;

	sign = 1;
	neg = 0;
	a = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\f' || str[i] == '\v' || str[i] == '\r')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (neg > 0)
			return (0);
		if (str[i] == '-')
			sign = -sign;
		neg++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		a = a * 10 + (str[i++] - '0');
	return ((int)a * sign);
}
