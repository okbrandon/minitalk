/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:06:28 by bsoubaig          #+#    #+#             */
/*   Updated: 2023/01/11 12:25:48 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	ft_error(char *str)
{
	ft_printf("%s%sAn error occurred :%s %s", RED, BOLD, RESET, str);
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

int	ft_atoi(const char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (str[i] == ' ')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result);
}
