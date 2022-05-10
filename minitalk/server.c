/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 18:07:33 by arecce            #+#    #+#             */
/*   Updated: 2022/05/10 19:17:41 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void	sig_handler(int sig)
{
	printf("Messaggio inviato!\n");
}

int	main(void)
{
	//int				pid;
	struct sigaction	ft_sig;

	ft_sig.sa_flags = SA_SIGINFO;
	ft_sig.sa_handler = sig_handler;
	//pid = getpid();
	printf("PID: %d\nWaiting...\n", getpid());
	sigaction(SIGUSR1, &ft_sig, NULL);
	while (1)
		pause();
}
