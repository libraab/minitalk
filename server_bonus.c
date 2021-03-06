/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 14:41:04 by abouhlel          #+#    #+#             */
/*   Updated: 2021/07/21 17:02:12 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	s;

	(void)argv;
	if (argc == 1)
	{
		pid = getpid();
		ft_putstr("My pid is: ");
		ft_putnbr(pid);
		ft_putchar('\n');
		s.sa_flags = SA_SIGINFO;
		s.sa_sigaction = ft_putbit;
		sigaction(SIGUSR1, &s, NULL);
		sigaction(SIGUSR2, &s, NULL);
		while (1)
			pause();
	}
	return (0);
}
