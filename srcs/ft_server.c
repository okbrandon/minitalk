/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 10:13:00 by bsoubaig          #+#    #+#             */
/*   Updated: 2022/12/29 12:29:35 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdlib.h>

void	ft_sig_handler(int sig, siginfo_t *sinfo, void *context)
{
	static char	c;
	static int	bit;
	static int	client_pid;

	(void) context;
	if (!client_pid)
	{
		bit = 0;
		c = 0;
		client_pid = sinfo->si_pid;
		ft_printf("[server] client_pid=%d\n", client_pid);
	}
	c |= (sig == SIGUSR2);
	bit++;
	ft_printf("bit=%d\n", bit);
	c <<= 1;
	usleep(100);
	kill(client_pid, SIGUSR2);
}

int	main(void)
{
	int					pid;
	struct sigaction	sact;

	pid = getpid();
	sigemptyset(&sact.sa_mask);
	sact.sa_flags = SA_SIGINFO;
	sact.sa_sigaction = ft_sig_handler;
	ft_printf("[server] PID=%d\n", pid);
	while (1)
	{
		sigaction(SIGUSR1, &sact, 0);
		sigaction(SIGUSR2, &sact, 0);
		sleep(1);
	}
	return (EXIT_FAILURE);
}
