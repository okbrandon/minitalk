/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 10:13:00 by bsoubaig          #+#    #+#             */
/*   Updated: 2023/01/11 11:17:07 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static int		g_char_received;

static void	ft_sig_handler(int sig, siginfo_t *sinfo, void *context)
{
	(void) context;
	(void) sinfo;
	if (sig == SIGUSR1)
		g_char_received = 1;
	else if (sig == SIGUSR2)
	{
		ft_printf("[from %d] Successfully got your message!\n", sinfo->si_pid);
		exit(EXIT_SUCCESS);
	}
}

static void	ft_char_to_binary(char c, int pid)
{
	int	bit;

	bit = 0;
	while (bit < 7)
	{
		g_char_received = 0;
		if ((c >> bit) & 1)
		{
			if (kill(pid, SIGUSR2) == -1)
				ft_error("An error occurred : signal can't be sent.");
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				ft_error("An error occurred : signal can't be sent.");
		}
		while (!g_char_received)
			pause();
		bit++;
		usleep(100);
	}
}

static void	ft_send_text(char *str, int len, int pid)
{
	int	i;

	i = 0;
	while (i <= len)
		ft_char_to_binary(str[i++], pid);
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sact;

	if (argc != 3)
		ft_error("Help : ./client <PID> <message>");
	pid = ft_atoi(argv[1]);
	if (!pid)
		ft_error("An error occurred : this pid is impossible.");
	sigemptyset(&sact.sa_mask);
	sact.sa_flags = SA_SIGINFO;
	sact.sa_sigaction = ft_sig_handler;
	sigaction(SIGUSR1, &sact, 0);
	sigaction(SIGUSR2, &sact, 0);
	ft_send_text(argv[2], ft_strlen(argv[2]), pid);
	return (0);
}
