/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 10:13:08 by bsoubaig          #+#    #+#             */
/*   Updated: 2023/01/10 19:04:22 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../ft_printf/srcs/ft_printf.h"
# include <signal.h>
# include <stdlib.h> 

void	ft_error(char *str);
int		ft_strlen(char *str);
int		ft_atoi(const char *str);

#endif
