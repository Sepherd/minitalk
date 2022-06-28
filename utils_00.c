/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_00.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgavioli <vgavioli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 12:13:31 by vgavioli          #+#    #+#             */
/*   Updated: 2022/06/26 09:15:46 by vgavioli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_error(int cc)
{
	if (cc)
		ft_printf("\n[INFO	]: //client unexpected%cerror.\n", ' ');
	else
		ft_printf("\n[INFO	]: //server unexpected%cerror.\n", ' ');
	exit(EXIT_FAILURE);
}
