/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_server.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 10:24:08 by arebelo           #+#    #+#             */
/*   Updated: 2022/03/07 14:56:16 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

static t_char	g_stru;

void	initialize_stru(void)
{
	g_stru.nb = 8;
	g_stru.c = 0;
}

void	end_signal(void)
{
	write(1, "\n", 1);
	kill(g_stru.client_pid, SIGUSR1);
}

void	handle_sigusr1(int sig, siginfo_t *info, void *context)
{
	(void) sig;
	(void) context;
	g_stru.client_pid = info->si_pid;
	g_stru.nb--;
	g_stru.c = g_stru.c | (1 << g_stru.nb);
	if (g_stru.nb == 0)
	{
		write(1, &g_stru.c, 1);
		if (g_stru.c == 0)
			end_signal();
		initialize_stru();
	}		
}

void	handle_sigusr2(int sig, siginfo_t *info, void *context)
{
	(void) sig;
	(void) context;
	g_stru.client_pid = info->si_pid;
	g_stru.nb--;
	if (g_stru.nb == 0)
	{
		write(1, &g_stru.c, 1);
		if (g_stru.c == 0)
			end_signal();
		initialize_stru();
	}		
}

int	main(void)
{
	struct sigaction	sa1;
	struct sigaction	sa2;

	initialize_stru();
	ft_printf("%d\n", getpid());
	sa1.sa_flags = SA_SIGINFO;
	sa2.sa_flags = SA_SIGINFO;
	sa1.sa_sigaction = handle_sigusr1;
	sa2.sa_sigaction = handle_sigusr2;
	sigaction(SIGUSR1, &sa1, NULL);
	sigaction(SIGUSR2, &sa2, NULL);
	pause();
	while (1)
		sleep(10);
	return (0);
}
