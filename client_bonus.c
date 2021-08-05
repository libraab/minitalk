/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 14:40:24 by abouhlel          #+#    #+#             */
/*   Updated: 2021/08/05 15:32:59 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

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
		if (ac == 2)
		{
			write(2, "A PID or a String is missing.\n", 33);
			exit (EXIT_FAILURE);
		}
	}
	write(1, "Message received.\n", 18);
	exit (EXIT_SUCCESS);
}
