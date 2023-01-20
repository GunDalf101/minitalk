/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennani <mbennani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:37:41 by mbennani          #+#    #+#             */
/*   Updated: 2022/12/28 03:36:21 by mbennani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
	static int	client;
	static int	d;
	static char	c;

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
