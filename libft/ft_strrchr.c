/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 12:21:35 by mberquer          #+#    #+#             */
/*   Updated: 2021/12/08 16:31:08 by mberquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*s2;

	s2 = NULL;
	while (*s)
	{
		if ((char) *s == (char) c)
			s2 = (char *) s;
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (s2);
}
