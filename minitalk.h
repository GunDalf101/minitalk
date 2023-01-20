/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennani <mbennani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 14:32:45 by mbennani          #+#    #+#             */
/*   Updated: 2022/12/28 03:38:19 by mbennani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <unistd.h>
# include <signal.h>
# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include "ft_printf/ft_printf.h" 

int		ft_printf(const char *format, ...);
int		ft_atoi(const char *str);

#endif