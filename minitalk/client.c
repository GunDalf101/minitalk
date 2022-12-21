/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennani <mbennani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:37:46 by mbennani          #+#    #+#             */
/*   Updated: 2022/12/22 00:35:11 by mbennani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
 
int	pid;

void	fortsignal(int sig, siginfo_t *info)
{
	// if (info->si_pid != pid)
	// 	exit (0);
}

void	signals7i7(int pid, char *msg)
{
	int i;
	int j;
	char c;
	struct sigaction act2;


	i = 0;
	act2.sa_handler = (void *)fortsignal;
	while(msg[i])
	{
		c = msg[i];
		j = 0;
		while(j < 8)
		{
			if(c & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			sigaction(SIGUSR1, &act2, NULL);
			pause();
			usleep(300);
			c >>= 1;
			j++;
		}
		i++;
	}	
}

int main(int ac, char **av)
{

	if (ac == 3)
	{
		pid = atoi(av[1]);
		signals7i7(pid, av[2]);
	}
}