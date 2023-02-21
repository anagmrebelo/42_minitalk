/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_client.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 10:24:11 by arebelo           #+#    #+#             */
/*   Updated: 2022/03/07 14:39:05 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

static void	conversion_to_binary(pid_t pid, char *c)
{	
	size_t	i;
	size_t	len;

	i = 0;
	len = (ft_strlen(c) + 1) * 8;
	while (i < len)
	{
		if (0 == (c[i / 8] & 1 << (~i & 7)))
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(200);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	if (argc == 3)
		conversion_to_binary(ft_atoi(argv[1]), argv[2]);
	else
		return (-1);
	return (0);
}
