/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:04:35 by mberquer          #+#    #+#             */
/*   Updated: 2021/12/17 16:28:47 by mberquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*s2;

	if (s)
	{
		i = 0;
		s2 = (char *)malloc((len + 1) * sizeof(char));
		if (!s2)
			return (NULL);
		if (start > ft_strlen(s))
		{
			s2[0] = '\0';
			return (s2);
		}
		while (i < len && s[start + i])
		{
			s2[i] = s[start + i];
			i++;
		}
		s2[i] = '\0';
		return (s2);
	}
	return (NULL);
}
