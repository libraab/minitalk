/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 14:40:10 by abouhlel          #+#    #+#             */
/*   Updated: 2021/07/16 22:17:05 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_global = 0;

void	ft_loula(int sig)
{
	(void)sig;
	g_global = 1;
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

int	main(int ac, char **av)
{
	int	pid;

	signal(SIGUSR1, ft_loula);
	if (ac == 1)
	{
		write(2, "A PID and a String are missing.\n", 37);
		exit (EXIT_FAILURE);
	}
	if (ac > 1 && ac < 4)
	{
		pid = ft_atoi(av[1]);
		ft_check_error(ac, av, pid);
		if (pid == 0)
		{
			write(2, "Error PID.\n", 12);
			exit (EXIT_FAILURE);
		}
		if (ac == 2)
		{
			write(2, "A PID or a String is missing.\n", 33);
			exit (EXIT_FAILURE);
		}
	}
	exit (EXIT_SUCCESS);
}
