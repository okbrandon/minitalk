/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:06:28 by bsoubaig          #+#    #+#             */
/*   Updated: 2023/01/09 20:08:51 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_error(char *str)
{
	ft_printf("%s", str);
	exit(EXIT_FAILURE);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_char_to_binary(char c, int pid)
{
	int	bit;

	bit = 0;
	while (bit < 7)
	{
		if ((c >> bit) & 1)
		{
			if (kill(pid, SIGUSR2) == -1)
				ft_error("Error sending signal");
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				ft_error("Error sending signal");
		}
		bit++;
		usleep(400);
	}
}

void	ft_send_text(char *str, int len, int pid)
{
	int	i;

	i = 0;
	while (i <= len)
		ft_char_to_binary(str[i++], pid);
}
