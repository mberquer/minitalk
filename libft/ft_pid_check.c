/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pid_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberquer <mberquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 12:14:09 by mberquer          #+#    #+#             */
/*   Updated: 2022/07/11 18:35:07 by mberquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	pid_check(char *pid)
{
	int	i;

	i = 0;
	if (pid[0] == '-')
		return (0);
	while (pid[i])
	{
		if (!ft_isdigit(pid[i]))
			return (0);
		i++;
	}
	if (ft_atoi(pid) == 0)
		return (0);
	return (1);
}
