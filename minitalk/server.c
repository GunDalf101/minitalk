/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennani <mbennani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:37:41 by mbennani          #+#    #+#             */
/*   Updated: 2022/12/22 00:32:35 by mbennani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdio.h>

void handler(int sig, siginfo_t	*info)
{
	static int	d;
	static char	c;

	if (sig == SIGUSR1)
		c |= 1 << d;	
	else if (sig == SIGUSR2)
		c &= ~(1 << d);
	d++;
	kill(info->si_pid, SIGUSR1);
	if  (d == 8)
	{
		write(1, &c, 1);
		c = 0;
		d = 0;
	}
			
}

int main()
{
	struct sigaction act;
	
	int pid = getpid();

	act.sa_handler = (void *)handler;
	printf("this is my pid ==> %d\n", pid);
	while(1)
	{
		sigaction(SIGUSR1, &act, NULL);
		sigaction(SIGUSR2, &act, NULL);
		pause();
	}
}