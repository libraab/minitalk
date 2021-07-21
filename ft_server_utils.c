/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 22:15:53 by abouhlel          #+#    #+#             */
/*   Updated: 2021/07/21 08:08:28 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar('-');
	}
	if (nb > 9)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
}

void	ft_send_msg(int num)
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

void	coco(int x, siginfo_t *y, void *z)
{
	(void)z;
	ft_send_msg(x);
	kill(y->si_pid, SIGUSR1);
}
