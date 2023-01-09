/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 10:13:08 by bsoubaig          #+#    #+#             */
/*   Updated: 2023/01/09 20:08:39 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../ft_printf/srcs/ft_printf.h"
# include <signal.h>
# include <stdlib.h>

int		ft_strlen(char *str);
void	ft_char_to_binary(char c, int pid);
void	ft_send_text(char *str, int len, int pid);

#endif