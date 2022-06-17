/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberquer <mberquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 15:29:32 by mberquer          #+#    #+#             */
/*   Updated: 2022/06/17 17:28:31 by mberquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	dosomthing(int signum)
{
	ft_printf("signum :%d\n", signum);
}
int	main()
{
	int pid;

	pid = getpid();
	ft_printf("PID: %d\n", pid);
	signal(SIGUSR1, dosomthing);
	while (1)
		pause();
}
