/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 12:32:13 by mberquer          #+#    #+#             */
/*   Updated: 2021/12/07 15:35:25 by mberquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	cha;

	ptr = (unsigned char *)s;
	cha = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		if (*ptr == cha)
			return ((void *)ptr);
		ptr++;
		i++;
	}
	return (0);
}
