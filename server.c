/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgavioli <vgavioli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 13:07:13 by vgavioli          #+#    #+#             */
/*   Updated: 2022/06/27 14:43:18 by vgavioli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	recover_char(char ch)
{
	while ((unsigned int)(ch) >= 0b10000000)
		ch -= 0b10000000;
	return (ch);
}

static void	check_client(int *cpid, siginfo_t *sinfo)
{
	if (!*cpid)
		*cpid = sinfo->si_pid;
	else if (*cpid != sinfo->si_pid)
		usleep(40);
}

static void	sighandler(int signum, siginfo_t *sinfo, void *v)
{
	static int	cpid;
	static int	bit;
	static int	ch;

	(void)v;
	check_client(&cpid, sinfo);
	ch |= (signum == SIGUSR2);
	bit++;
	if (bit == 0b1000)
	{
		ft_printf("%c", ch);
		if (recover_char(ch) == '\0')
		{
			ft_printf("\n[INFO ]: Received from %d PID, responding.\n", cpid);
			bit = 0;
			kill(cpid, SIGUSR2);
			cpid = 0;
		}
		else
			kill(cpid, SIGUSR1);
		bit = 0;
	}
	ch <<= 1;
	usleep(5);
}

int	main(void)
{
	int					pid;
	struct sigaction	action;

	pid = getpid();
	ft_printf("[INFO	]: PID %d\n", pid);
	action.sa_sigaction = sighandler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &action, 0);
	sigaction(SIGUSR2, &action, 0);
	while (5)
		pause();
}
