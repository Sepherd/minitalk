/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 18:07:30 by arecce            #+#    #+#             */
/*   Updated: 2022/05/10 19:17:04 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>
#include <unistd.h>
#include <stdio.h>

int	ft_atoi(char *str)
{
	int	i;
	int	neg;
	int	num;
	int	counter;

	i = 0;
	neg = 1;
	num = 0;
	counter = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	while ((str[i] == '-' || str[i] == '+') && counter++ == 0)
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	num *= neg;
	return (num);
}

// void	msg_received(int x)
// {
// 	if (x == SIGUSR1)
// 		write(1, "Messaggio ricevuto\n", 19);
// 	return ;
// }

// void	msg_tosend(int sig, int pid)
// {
// 	printf("Messaggio inviato!");
// 	kill(pid, SIGUSR1);
// }

int	main(int argc, char **argv)
{
	int	pid;

	if (argc < 2)
		return (printf("Error!\n"));
	pid = ft_atoi(argv[1]);
	// signal(SIGUSR1, msg_received);
	if (argc == 2 && pid > 0)
	{
		g_message = argv[2];
		kill(pid, SIGUSR1);
	}
	else
		return (printf("Error PID.\n"));
	return (0);
}
