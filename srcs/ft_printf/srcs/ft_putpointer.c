/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:49:19 by bsoubaig          #+#    #+#             */
/*   Updated: 2022/11/13 19:38:51 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printpointer(unsigned long long n)
{
	int	i;

	i = 0;
	if (n >= 16)
	{
		i += ft_printpointer(n / 16);
		i += ft_printpointer(n % 16);
	}
	else
	{
		if (n < 10)
			i += ft_putchar(n + '0');
		else
			i += ft_putchar(n + 'a' - 10);
	}
	return (i);
}

int	ft_putpointer(unsigned long long n)
{
	int	i;

	i = 0;
	i += ft_putstr("0x");
	i += ft_printpointer(n);
	return (i);
}
