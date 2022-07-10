/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:09:59 by mberquer          #+#    #+#             */
/*   Updated: 2021/12/17 11:58:00 by mberquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int		i;
	char	*d2;
	char	*s2;

	d2 = (char *)dest;
	s2 = (char *)src;
	if (dest || src)
	{
		if (d2 >= s2 && d2 < (s2 + n))
		{
			i = n - 1;
			while (i >= 0)
			{
				d2[i] = s2[i];
				i--;
			}
			return (dest);
		}
		ft_memcpy(d2, s2, n);
		return (dest);
	}
	return (NULL);
}
