/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 10:13:00 by bsoubaig          #+#    #+#             */
/*   Updated: 2022/12/30 12:17:22 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>
#include <stdlib.h>

void	ft_sig_handler(int sig, siginfo_t *sinfo, void *context)
{
	static int	c;
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
	c += ((sig & 1) << bit);
	bit++;
	if (bit == 7)
	{
		ft_printf("%c", c);
/* 		if (c == 0)
			ft_printf("\n"); */
		bit = 0;
		c = 0;
	}
	usleep(100);
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
