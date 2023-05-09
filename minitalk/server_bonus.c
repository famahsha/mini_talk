/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Famahsha < famahsha@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:15:32 by Famahsha          #+#    #+#             */
/*   Updated: 2023/05/05 16:04:11 by Famahsha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	check_signal(int signum, siginfo_t *info, void *context)
{
	static int	bit;
	static int	character;

	(void)context;
	if (signum == SIGUSR1)
		character = character | (1 << (7 - bit));
	bit++;
	if (bit == 8)
	{
		if (character == 0)
			(kill(info->si_pid, SIGUSR2));
		else
			kill(info->si_pid, SIGUSR1);
		ft_putchar(character);
		bit = 0;
		character = 0;
	}
}

int	main(int ac, char **av)
{
	struct sigaction	sa;
	int					pid;

	(void)ac;
	(void)av;
	pid = getpid();
	ft_putstr("PID :");
	ft_putnbr(pid);
	ft_putchar('\n');
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = check_signal;
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	while (1)
		pause();
}
