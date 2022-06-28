/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgavioli <vgavioli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 08:59:51 by vgavioli          #+#    #+#             */
/*   Updated: 2022/06/27 14:51:14 by vgavioli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static unsigned int	check_spid(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(ft_isdigit(i++[str])))
		{
			pf_log("es", "", "Server PID is not valid", "");
			exit(1);
		}
	}
	return (ft_atoi(str));
}

static void	received(int signum)
{
	pf_log("ss", "Received signal id <", ft_itoa(signum), ">");
	if (signum == SIGUSR2)
		exit(0);
}

static void	send_char(unsigned int spid, unsigned char ch)
{
	int	bitp;

	bitp = 0;
	while (bitp < 0b00001000)
	{	
		if (ch & 0b10000000)
		{
			if (kill(spid, SIGUSR2) == -1)
				signal_error(999);
		}
		else
		{
			if (kill(spid, SIGUSR1) == -1)
				signal_error(999);
		}
		ch <<= 1;
		bitp++;
		usleep(TSLP);
	}
}

static void	send_text(int spid, char *str)
{
	pf_log("is", "Sending '", str, "'");
	while (str[0])
		send_char(spid, str++[0]);
	pf_log("is", "", "Sent all the text", "");
	send_char(spid, '\0');
}

int	main(int argn, char **argv)
{
	unsigned int	spid;
	unsigned int	pid;
	char			*num;
	char			*str;

	pid = getpid();
	ft_printf("[INFO	]: PID %d\n", pid);
	if (argn != 3)
		pf_log("es", "", "Wrong number of arguments", "");
	if (argn != 3)
		return (1);
	num = argv[1];
	str = argv[2];
	spid = check_spid(num);
	pf_log("is", "Server PID --> ", num, "");
	signal(SIGUSR1, received);
	signal(SIGUSR2, received);
	send_text(spid, str);
	while (1)
		pause();
	return (0);
}
