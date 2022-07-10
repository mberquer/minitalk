/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:41:19 by mberquer          #+#    #+#             */
/*   Updated: 2021/12/17 16:58:33 by mberquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_count(char const *s, char c)
{
	size_t	i;
	int		j;
	size_t	count;

	i = 0;
	j = 1;
	count = 0;
	while (s[i])
	{
		if (j && s[i] != c)
		{
			count++;
			j = 0;
		}
		else if (!j && s[i] == c)
			j = 1;
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**s2;
	int		i;
	int		a;
	int		buffer;

	i = -1;
	a = 0;
	buffer = -1;
	s2 = (char **)malloc(((ft_count(s, c) + 1) * sizeof(char *)));
	if (!s2)
		return (NULL);
	while (s[++i])
	{	
		if (buffer >= 0 && s[i] == c)
		{
			s2[a++] = ft_substr(s, buffer, i - buffer);
			buffer = -1;
		}
		if (buffer < 0 && s[i] != c)
			buffer = i;
	}
	if (buffer >= 0)
		s2[a++] = ft_substr(s, buffer, i - buffer);
	s2[a] = NULL;
	return (s2);
}
