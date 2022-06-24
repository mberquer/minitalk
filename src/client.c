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

void	sending_bits(int pid, int *str)
{
	static int	s_pid = 0;
	static char	*message = 0;
	static int	shift = -1;

	if (str)
		message = str;
	if (pid)
		s_pid = pid;
	if (message[++shift / 8])
	{
			if (message[shift / 8] & (128 >> shift % 8))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
	}
}

int	main(int argc, char *argv[])
{
	int	pid;
	int	i;
	int	shift;

	i = -1;
	shift = -1;
	if (argc != 3)
	{
   	ft_printf("client: invalid arguments\n");
   	exit(EXIT_FAILURE);
	}
	pid = atoi(argv[1]);
	signal(SIGUSR1, sending_bits(0, 0));
	signal(SIGUSR2, handler_2);
}