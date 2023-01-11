/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 10:13:00 by bsoubaig          #+#    #+#             */
/*   Updated: 2023/01/11 12:28:27 by bsoubaig         ###   ########.fr       */
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
		ft_printf("%s%s%d%s: %sSuccessfully %sgot your message! ✅\n",
			PURPLE, BOLD, sinfo->si_pid, RESET, GREEN, RESET);
		exit(EXIT_SUCCESS);
	}
}

static void	ft_send_bit(char c, int bit, int pid)
{
	if (c & (128 >> bit))
	{
		if (kill(pid, SIGUSR2) == -1)
			ft_error("signal can't be sent. ❌\n");
	}
	else
	{
		if (kill(pid, SIGUSR1) == -1)
			ft_error("signal can't be sent. ❌\n");
	}
}

static void	ft_char_to_binary(char c, int pid)
{
	int	bit;
	int	time_out;

	bit = 0;
	time_out = 0;
	while (bit < 8)
	{
		g_char_received = 0;
		ft_send_bit(c, bit, pid);
		while (!g_char_received)
		{
			if (time_out >= 3)
				ft_error("server did not respond in time. 💀\n");
			time_out++;
			sleep(1);
		}
		time_out = 0;
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
		ft_error("incorrect usage! ./client <PID> <message> 📝\n");
	pid = ft_atoi(argv[1]);
	if (!pid)
		ft_error("this pid is impossible.\n");
	sigemptyset(&sact.sa_mask);
	sact.sa_flags = SA_SIGINFO;
	sact.sa_sigaction = ft_sig_handler;
	sigaction(SIGUSR1, &sact, 0);
	sigaction(SIGUSR2, &sact, 0);
	ft_send_text(argv[2], ft_strlen(argv[2]), pid);
	return (0);
}
