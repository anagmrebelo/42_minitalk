/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_client_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarebelo <anarebelo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 10:24:11 by arebelo           #+#    #+#             */
/*   Updated: 2023/02/21 22:55:31 by anarebelo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "minitalk.h"

void	handler_sigusr1(int sig)
{
	(void) sig;
	ft_printf("Message received\n");
	exit(1);
}

static void	conversion_to_binary(pid_t pid, char *c)
{	
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(c);
	while ((i < 8 * (len + 1)))
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
	struct sigaction	sa1;

	if (argc == 3)
	{
		sa1.sa_flags = SA_SIGINFO;
		sa1.sa_handler = &handler_sigusr1;
		sigaction(SIGUSR1, &sa1, NULL);
		conversion_to_binary(ft_atoi(argv[1]), argv[2]);
		pause();
	}
	else
		return (-1);
	return (0);
}
