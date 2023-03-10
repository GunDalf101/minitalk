/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennani <mbennani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:37:46 by mbennani          #+#    #+#             */
/*   Updated: 2022/12/28 02:24:55 by mbennani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	fortsignal(int sig, siginfo_t *info)
{
	if (sig == SIGUSR1)
		ft_printf("Message received at PID: %d\n", info->si_pid);
	exit (0);
}

void	send_char(char c, int pid)
{
	int	j;

	j = 0;
	while (j < 8)
	{
		if (c & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(300);
		c >>= 1;
		j++;
	}
}

void	signals7i7(int pid, char *msg)
{
	int					i;
	struct sigaction	act2;

	i = 0;
	act2.sa_handler = (void *)fortsignal;
	while (msg[i])
	{
		send_char(msg[i], pid);
		i++;
	}
	send_char(0, pid);
	while (1)
	{
		sigaction(SIGUSR1, &act2, NULL);
		pause();
	}
}

int	main(int ac, char **av)
{
	if (ac == 3)
		signals7i7(ft_atoi(av[1]), av[2]);
}
