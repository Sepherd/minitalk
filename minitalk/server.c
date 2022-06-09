/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 18:07:33 by arecce            #+#    #+#             */
/*   Updated: 2022/06/09 13:42:48 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


void	sig_handler(int sig)
{
	static unsigned char	c = 0;
	static unsigned int		i = 0;
	
	c |= (sig == SIGUSR2);
	if (++i == 8)
	{
		i = 0;
		write(1, &c, 1);
		c = 0;
	}
	else
		c = c << 1;	
}

int	main(void)
{
	struct sigaction	ft_sig;

	ft_sig.sa_flags = SA_SIGINFO;
	ft_sig.sa_handler = sig_handler;
	printf("PID: %d\nWaiting...\n", getpid());
	// sigaction(SIGUSR1, &ft_sig, 0);
	// sigaction(SIGUSR2, &ft_sig, 0);
	//printf("%s", g_message);
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	while (1)
		pause();
	return (0);
}
