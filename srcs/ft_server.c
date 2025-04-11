/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 10:13:00 by bsoubaig          #+#    #+#             */
/*   Updated: 2025/04/11 16:51:01 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

/**
 * @brief Function used to display the banner.
 *
 * @param pid		The server pid
 */
static void	ft_display_banner(int pid)
{
	ft_printf("%s%s    __  ________   _______________    __    __ __\n",
		PURPLE, BOLD);
	ft_printf("%s%s   /  |/  /  _/ | / /  _/_  __/   |  / /   / //_/\n",
		PURPLE, BOLD);
	ft_printf("%s%s  / /|_/ // //  |/ // /  / / / /| | / /   / ,<\n",
		PURPLE, BOLD);
	ft_printf("%s%s / /  / // // /|  // /  / / / ___ |/ /___/ /| |\n",
		PURPLE, BOLD);
	ft_printf("%s%s/_/  /_/___/_/ |_/___/ /_/ /_/  |_/_____/_/ |_|\n",
		PURPLE, BOLD);
	ft_printf("%s               %s»» PID: %s%s%d%s%s ««%s\n\n",
		RESET, GREY, GREEN, BOLD, pid, RESET, GREY, RESET);
}

/**
 * @brief Function used to store the received character
 * in a string and print it when the end of the message
 *
 * @param c			The character to store
 */
static void	ft_send_char(char c)
{
	static char	*str;
	char		tmp[2];

	if (!str)
	{
		str = malloc(1);
		*str = '\0';
	}
	tmp[0] = c;
	tmp[1] = '\0';
	str = ft_free_to_join(str, tmp);
	if (c == 0)
	{
		ft_printf("%s\n", str);
		free(str);
		str = NULL;
	}
}

/**
 * @brief Function used to catch the signals received by
 * the server from the client.
 *
 * @param sig 		The signal received
 * @param sinfo 	The different informations about the source
 * @param context 	The context (ignored)
 */
void	ft_sig_handler(int sig, siginfo_t *sinfo, void *context)
{
	static int		c;
	static int		bit;
	static pid_t	client_pid;

	(void) context;
	if (!c || client_pid != sinfo->si_pid)
	{
		c = 255;
		bit = 0;
	}
	client_pid = sinfo->si_pid;
	if (sig == SIGUSR1)
		c ^= (128 >> bit);
	else if (sig == SIGUSR2)
		c |= (128 >> bit);
	if (++bit == 8)
	{
		ft_send_char(c);
		if (c == 0)
			kill(client_pid, SIGUSR2);
		bit = 0;
		c = 255;
	}
	usleep(100);
	kill(client_pid, SIGUSR1);
}

/**
 * @brief The main program of the server.
 */
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
	ft_display_banner(pid);
	while (1)
		pause();
	return (EXIT_FAILURE);
}
