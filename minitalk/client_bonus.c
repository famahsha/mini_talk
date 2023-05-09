/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Famahsha < famahsha@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:53:21 by Famahsha          #+#    #+#             */
/*   Updated: 2023/05/06 15:17:47 by Famahsha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include<stdio.h>

static void	check_message(int signum)
{
	if (signum == SIGUSR2)
	{
		ft_putstr("characters recieved successfully\n");
		exit(0);
	}
}

void	send_message(int pid, char *str)
{
	int	bit;
	int	i;

	bit = 7;
	i = 0;
	while (str[i])
	{
		while (bit >= 0)
		{
			if (str[i] & (1 << bit))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(500);
			bit--;
		}
		i++;
		bit = 7;
	}
	bit = 8;
	while (bit--)
	{
		kill(pid, SIGUSR2);
		usleep(100);
	}
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac != 3)
	{
		ft_putstr("error :wrong number of arguments\n");
		return (1);
	}
	pid = ft_atoi(av[1]);
	signal(SIGUSR1, check_message);
	signal(SIGUSR2, check_message);
	if (pid <= 0)
	{
		ft_putstr("invalid pid\n");
		return (1);
	}
	send_message(pid, av[2]);
}
