/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 14:40:10 by abouhlel          #+#    #+#             */
/*   Updated: 2021/08/05 15:32:21 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
	exit (EXIT_SUCCESS);
}
