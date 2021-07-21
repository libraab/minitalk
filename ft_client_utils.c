/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 07:56:04 by abouhlel          #+#    #+#             */
/*   Updated: 2021/07/21 18:03:32 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"
#include "minitalk.h"

static int	g_global = 0;
static int	g_signo;
static int	g_count = 0;

void	ft_loula(int sig)
{
	if ((g_count == 0) || g_signo == sig)
	{
		g_global = 1;
		g_signo = sig;
		g_count++;
	}
}

int	ft_convert_char(char c, int pid)
{
	int	x;
	int	y;

	x = 7;
	while (x >= 0)
	{
		g_global = 0;
		if (c >> x & 1)
		{
			usleep(100);
			y = kill(pid, SIGUSR1);
		}
		else
		{
			usleep(100);
			y = kill(pid, SIGUSR2);
		}
		if (y == -1)
			return (0);
		x--;
		while (g_global == 0)
		{
		}
	}
	return (1);
}

void	ft_error_msg(void)
{
	write(2, "Invalid PID.\n", 14);
	exit (EXIT_FAILURE);
}

void	ft_check_error(int ac, char **av, int pid)
{
	int	i;
	int	x;

	i = 0;
	while (av[1][i++])
	{
		if ((av[1][i] >= 'a' && av[1][i] <= 'z')
			|| (av[1][i] >= 'A' && av[1][i] <= 'Z'))
			ft_error_msg();
	}
	if (ac == 3)
	{
		i = 0;
		while (av[2][i])
		{
			x = ft_convert_char(av[2][i++], pid);
			if (x == 0)
				ft_error_msg();
		}
	}
}

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
