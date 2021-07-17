/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 18:05:33 by abouhlel          #+#    #+#             */
/*   Updated: 2021/07/17 18:05:35 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minitalk_bonus.h"

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
