/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:06:28 by bsoubaig          #+#    #+#             */
/*   Updated: 2025/04/11 16:49:52 by bsoubaig         ###   ########.fr       */
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

/**
 * @brief Basic implementation of ft_strjoin from libft.
 *
 * @param s1			The first char array
 * @param s2			The second char array
 * @return char* 		The joined char array
 */
char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	str = (char *) malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

char	*ft_free_to_join(char *s1, char *s2)
{
	char	*str;

	if (!s1)
	{
		s1 = (char *) malloc(1);
		s1[0] = '\0';
	}
	str = ft_strjoin(s1, s2);
	free(s1);
	return (str);
}
