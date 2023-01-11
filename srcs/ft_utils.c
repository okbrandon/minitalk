/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:06:28 by bsoubaig          #+#    #+#             */
/*   Updated: 2023/01/11 15:50:04 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

/**
 * @brief Function used to print a basic error message
 * then exit the program with a failure.
 * 
 * @param str 			The message to display
 */
void	ft_error(char *str)
{
	ft_printf("%s%sAn error occurred :%s %s", RED, BOLD, RESET, str);
	exit(EXIT_FAILURE);
}

/**
 * @brief Basic function used to return the length of
 * a char array.
 * 
 * @param str 			The char array
 * @return int 			The length of the char array
 */
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/**
 * @brief Basic implementation of ft_atoi from libft.
 * 
 * @param str 			The char array containing a number
 * @return int 			The extracted number
 */
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
