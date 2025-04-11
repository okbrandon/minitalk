/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 10:13:08 by bsoubaig          #+#    #+#             */
/*   Updated: 2025/04/11 16:50:02 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../srcs/ft_printf/srcs/ft_printf.h"
# include <signal.h>
# include <stdlib.h>

# ifndef RED
#  define RED "\033[0;31m"
# endif

# ifndef PURPLE
#  define PURPLE "\033[38;5;141m"
# endif

# ifndef GREY
#  define GREY "\033[38;5;240m"
# endif

# ifndef GREEN
#  define GREEN "\033[38;5;46m"
# endif

# ifndef RESET
#  define RESET "\033[0m"
# endif

# ifndef BOLD
#  define BOLD "\033[1m"
# endif

void	ft_error(char *str);
int		ft_strlen(char *str);
int		ft_atoi(const char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_free_to_join(char *s1, char *s2);

#endif
