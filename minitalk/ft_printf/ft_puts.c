/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennani <mbennani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 08:05:15 by mbennani          #+#    #+#             */
/*   Updated: 2022/11/01 17:58:15 by mbennani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd(char c, int fd, int *returned)
{
	if (write(fd, &c, 1))
	{
		*returned += 1;
		return ;
	}
	*returned = -1;
}

void	ft_putstr_fd(char *s, int fd, int *returned)
{
	int	i;

	i = 0;
	if (!s)
	{
		ft_putstr_fd("(null)", 1, returned);
		return ;
	}
	while (s[i] && *returned > -1)
	{
		write(fd, &s[i], 1);
		*returned += 1;
		i++;
	}
}

void	ft_putnbr_fd(int n, int fd, int *returned)
{
	char	c;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		*returned += 11;
	}
	else if (n >= 0 && n <= 9 && *returned > -1)
	{
		c = n + 48;
		write (fd, &c, 1);
		*returned += 1;
	}
	else if (n < 0)
	{
		write (fd, "-", 1);
		*returned += 1;
		ft_putnbr_fd (-n, fd, returned);
	}
	else if (n > 0)
	{
		ft_putnbr_fd (n / 10, fd, returned);
		ft_putnbr_fd (n % 10, fd, returned);
	}
}

void	ft_putunsigned_fd(unsigned int n, int fd, int *returned)
{
	char	c;

	if (n >= 0 && n <= 9 && *returned > -1)
	{
		c = n + 48;
		write (fd, &c, 1);
		*returned += 1;
	}
	else if (n > 0)
	{
		ft_putnbr_fd (n / 10, fd, returned);
		ft_putnbr_fd (n % 10, fd, returned);
	}
}
