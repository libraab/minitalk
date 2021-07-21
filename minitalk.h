/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 14:40:38 by abouhlel          #+#    #+#             */
/*   Updated: 2021/07/21 16:57:28 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <stdlib.h>

void	ft_check_error(int ac, char **av, int pid);
void	ft_error_msg(void);
void	ft_loula(int sig);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
void	ft_putbit(int num, siginfo_t *y, void *z);
int		ft_convert_char(char c, int pid);
int		ft_atoi(const char *str);

#endif
