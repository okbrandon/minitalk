/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 10:13:00 by bsoubaig          #+#    #+#             */
/*   Updated: 2023/01/05 19:28:12 by bsoubaig         ###   ########.fr       */
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
		client_pid = sinfo->si_pid;
		ft_printf("[server] client_pid=%d\n", client_pid);
	}
	//c += ((sig & 1) << bit);
	c |= sig == SIGUSR2;
	bit++;
	if (bit < 8)
		c <<= 1;
	if (bit == 8)
	{
		ft_printf("%c", c);
		if (c == 0)
			ft_printf("\n");
		bit = 0;
		c = 0;
	}
	usleep(300);
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
