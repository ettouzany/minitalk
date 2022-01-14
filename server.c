/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: net-touz <net-touz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 23:37:21 by net-touz          #+#    #+#             */
/*   Updated: 2022/01/05 23:45:29 by net-touz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <stdint.h>
#include <libc.h>

char	*g_str = NULL;

char	*add_one(void)
{
	char	*s;
	int		i;

	i = 0;
	if (!g_str)
		return (NULL);
	s = malloc(sizeof(char) * strlen(g_str) + 2);
	if (!s)
		return ((write(1, "notaloc\n", 8)), NULL);
	while (i < strlen(g_str))
	{
		s[i] = g_str[i];
		i++;
	}
	s[i++] = 0;
	s[i] = 0;
	return (free(g_str), s);
}

void	handler_sigusr(int sig, siginfo_t *info, void *context)
{
	static int	count;
	static int	j;

	if (count == 0 && j == 0)
	{
		g_str = malloc(sizeof(char) + 1);
		g_str[count] = 0;
		g_str[count + 1] = 0;
	}
	if (g_str)
		g_str[count] = !(sig-30) ? g_str[count] << 1 : (g_str[count] << 1) + 1;
	j++;
	if (j > 7)
	{
		if (g_str[count] == 0)
		{
			write(1, g_str, count);
			if (info->si_pid)
				kill(info->si_pid, SIGUSR2);
			free(g_str);
			g_str = NULL;
			count = 0;
			j = 0;
		}
		else
		{
			count++;
			g_str = add_one();
		}
		j = 0;
	}
}

static void	handle_host_signal(void)
{
	struct sigaction	satmp;

	satmp.sa_flags = SA_SIGINFO;
	satmp.sa_sigaction = handler_sigusr;
	sigaction(SIGUSR1, &satmp, NULL);
	sigaction(SIGUSR2, &satmp, NULL);
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	printf("%d\n", pid);
	HandleHostSignal();
	while (1)
		usleep(1);
}
