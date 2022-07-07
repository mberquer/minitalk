/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberquer <mberquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 03:11:07 by mberquer          #+#    #+#             */
/*   Updated: 2022/06/22 03:12:42 by mberquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	send_null(int pid, char *str)
{
	static int	i = 0;

	if (i++ != 8)
	{
		kill(pid, SIGUSR1)
		return (0);
	}
	return (1);
}

void	sending_bits(int pid, char *str)
{
	static int	s_pid = 0;
	static char	*message = 0;
	static int	shift = -1;

	if (str)
		message = ft_strdup(str);
	if (pid)
		s_pid = pid;
	if (message[++shift / 8])
	{
			if (message[shift / 8] & (0x80 >> shift % 8))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
	}
	if (!send_null(s_pid, message))
		return (0);
	free(message);
	return (1);
}

void	handler_sigusr(int signum)
{
	int	end;

	end = 0;
	if (signum == SIGUSR1)
		end = sending_bit(0, 0);
	else if (signum == SIGUSR2)
	{
		ft_printf("client: server ended unexpectdly.\n");
		exit(EXIT_FAILURE);
	}
	if (end)
	{
		ft_printf("client: operation successful.\n");
		exit(EXIT_SUCCESS);
	}
}

int	main(int argc, char *argv[])
{
	if (argc != 3 || !pid_check(argv[1]))
	{
	ft_printf("client: invalid arguments\n");
   	exit(EXIT_FAILURE);
	}
	signal(SIGUSR1, handler_sigusr);
	signal(SIGUSR2, handler_sigusr);
	sending_bit(ft_atoi(argv[1]), argv[2])
	sleep(20000);
}