/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 10:13:00 by bsoubaig          #+#    #+#             */
/*   Updated: 2023/01/11 11:17:12 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	ft_is_process_running(pid_t pid)
{
	if (kill(pid, 0) == -1)
		ft_error("An error occurred : the client is not answering...");
}

void	ft_sig_handler(int sig, siginfo_t *sinfo, void *context)
{
	static int		c;
	static int		bit;
	pid_t			client_pid;

	(void) context;
	client_pid = sinfo->si_pid;
	ft_is_process_running(client_pid);
	c += ((sig & 1) << bit);
	bit++;
	if (bit == 7)
	{
		ft_printf("%c", c);
		if (c == 0)
		{
			ft_printf("\n");
			kill(client_pid, SIGUSR2);
		}
		bit = 0;
		c = 0;
	}
	usleep(100);
	kill(client_pid, SIGUSR1);
}

int	main(void)
{
	int					pid;
	struct sigaction	sact;

	pid = getpid();
	sigemptyset(&sact.sa_mask);
	sact.sa_flags = SA_SIGINFO;
	sact.sa_sigaction = ft_sig_handler;
	sigaction(SIGUSR1, &sact, 0);
	sigaction(SIGUSR2, &sact, 0);
	ft_printf("[server] PID=%d\n", pid);
	while (1)
		pause();
	return (EXIT_FAILURE);
}
