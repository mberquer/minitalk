/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_minitalk.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberquer <mberquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 12:43:12 by mberquer          #+#    #+#             */
/*   Updated: 2022/07/11 01:20:23 by mberquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin_mt(char const *s1, char const c)
{
	char	*s3;
	int		i;

	i = 0;
	if (s1 && c)
	{
		s3 = (char *)malloc((ft_strlen(s1) + 2) * sizeof(char));
		if (!s3)
			return (NULL);
		while (s1[i])
		{
			s3[i] = s1[i];
			i++;
		}
		s3[i] = c;
		s3[++i] = '\0';
		free(s1);
		return (s3);
	}
	return (NULL);
}
