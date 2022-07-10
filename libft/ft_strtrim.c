/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:50:07 by mberquer          #+#    #+#             */
/*   Updated: 2021/12/17 16:59:34 by mberquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	long int	i;
	long int	j;
	char		*s2;

	if (s1)
	{
		i = 0;
		j = ft_strlen(s1) - 1;
		while (ft_strchr(set, s1[i]) && s1[i])
			i++;
		while (j >= 0 && ft_strchr(set, s1[j]))
			j--;
		if (j < i)
		{
			s2 = ft_calloc(1, 1);
			if (!s2)
				return (NULL);
			return (s2);
		}
		s2 = ft_substr(s1, i, j - i + 1);
		return (s2);
	}
	return (NULL);
}
