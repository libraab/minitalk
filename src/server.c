/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 14:37:35 by abouhlel          #+#    #+#             */
/*   Updated: 2021/07/17 00:36:20 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minitalk.h"

static void	ft_send_msg(int num)
{
	static char	b;
	static int	pos;

	if (num == SIGUSR1)
		b += 1 << (7 - pos);
	pos++;
	if (pos == 8)
	{
		ft_putchar(b);
		pos = 0;
		b = 0;
	}
}

static void	coco(int x, siginfo_t *y, void *z)
{
	(void)z;
	ft_send_msg(x);
	kill(y->si_pid, SIGUSR1);
}

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
		s.sa_sigaction = coco;
		sigaction(SIGUSR1, &s, NULL);
		sigaction(SIGUSR2, &s, NULL);
		while (1)
		{
		}
	}
	return (0);
}
