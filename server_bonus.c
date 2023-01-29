/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennani <mbennani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:18:48 by mbennani          #+#    #+#             */
/*   Updated: 2023/01/29 20:25:22 by mbennani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int			g_unisize;

int	unitoomuch(unsigned char c)
{
	if ((c >> 4) == 0b1100)
		return (2);
	else if ((c >> 4) == 0b1110)
		return (3);
	else if ((c >> 4) == 0b1111)
		return (4);
	return (1);
}

void	ultrauni(int pid, unsigned char c)
{
	static unsigned int	cpp;
	static int			i;
	static int			client;

	if (client != pid)
	{
		client = pid;
		write(1, "\n", 1);
		g_unisize = 0;
		cpp = 0;
		i = 0;
	}
	if (g_unisize == 0)
		g_unisize = unitoomuch(c);
	cpp |= (c << i++ *8);
	if (g_unisize == i)
	{
		write(STDOUT_FILENO, &cpp, g_unisize);
		g_unisize = 0;
		cpp = 0;
		i = 0;
	}
}

void	writesig(int c, int client)
{
	if (c == 0)
	{
		usleep(500);
		kill(client, SIGUSR1);
	}
	write(1, &c, 1);
}

void	handler(int sig, siginfo_t	*info)
{
	static int				client;
	static int				d;
	static unsigned char	c;

	if (client != info->si_pid)
	{
		client = info->si_pid;
		write(1, "\n", 1);
		c = 0;
		d = 0;
	}
	if (sig == SIGUSR1)
		c |= 1 << d;
	else if (sig == SIGUSR2)
		c &= ~(1 << d);
	d++;
	if (d == 8)
	{
		if (c & (1 << 7) || g_unisize != 0)
			ultrauni(info->si_pid, c);
		else
			writesig(c, client);
		c = 0;
		d = 0;
	}
}

int	main(int ac, char **av)
{
	struct sigaction	act;
	int					pid;

	(void)ac;
	(void)av;
	pid = getpid();
	act.sa_handler = (void *)handler;
	ft_printf("this is my pid ==> %d\n", pid);
	while (1)
	{
		sigaction(SIGUSR1, &act, NULL);
		sigaction(SIGUSR2, &act, NULL);
		pause();
	}
}
