/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 18:07:30 by arecce            #+#    #+#             */
/*   Updated: 2022/06/09 14:25:40 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

void	msg_received(int sig)
{
	if (sig == SIGUSR1)
		write(1, "Messaggio ricevuto\n", 19);
	return ;
}

void	msg_tosend(int pid, char *msg)
{
 	char	c;
	int		i;
		
	while (*msg)
	{
		i = 8;
		c = *msg++;
		while(i--)
		{
			if (c >> i & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(100);
		}
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	char *msg;

	if (argc < 3)
		return (printf("Error!\n"));
	pid = ft_atoi(argv[1]);
	signal(SIGUSR1, msg_received);
	if (argc == 3 && pid > 0)
	{
		msg = argv[2];
		msg_tosend(pid, msg);
		msg_tosend(pid, "\n");
	}
	else
		return (printf("Error PID!\n"));
	return (0);
}
