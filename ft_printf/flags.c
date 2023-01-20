/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennani <mbennani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 11:31:19 by mbennani          #+#    #+#             */
/*   Updated: 2022/12/28 02:33:07 by mbennani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	flag_getter(const char *format)
{
	if (*format == '%' && *(format + 1) == 'c')
		return (1);
	else if (*format == '%' && *(format + 1) == 's')
		return (2);
	else if (*format == '%' && *(format + 1) == 'p')
		return (3);
	else if (*format == '%' && (*(format + 1) == 'd' || *(format + 1) == 'i'))
		return (4);
	else if (*format == '%' && *(format + 1) == 'u')
		return (5);
	else if (*format == '%' && *(format + 1) == 'x')
		return (6);
	else if (*format == '%' && *(format + 1) == 'X')
		return (7);
	else if (*format == '%' && *(format + 1) == '%')
		return (8);
	else if (*format == '%')
		return (9);
	return (0);
}

static int	isoverflow(long long int prev, long long int curr)
{
	if (curr / 10 == prev)
		return (0);
	return (1);
}

static int	itisspace(const char *str, int *pi)
{
	int	count;
	int	i;

	i = 0;
	count = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 45)
	{
		count = -1;
		i++;
	}
	else if (str[i] == 43)
		i++;
	*pi = i;
	return (count);
}

int	ft_atoi(const char *str)
{
	int				sign;
	long long int	res;
	long long int	prv;
	int				i;

	res = 0;
	sign = itisspace(str, &i);
	while (str[i] && str[i] >= 48 && str[i] <= 57)
	{
		prv = res;
		res = res * 10 + (str[i] - 48);
		if (isoverflow(prv, res) == 1)
		{
			if (sign == -1)
				return (0);
			return (-1);
		}
		i++;
	}
	res *= sign;
	return (res);
}
