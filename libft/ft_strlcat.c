/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:56:22 by mberquer          #+#    #+#             */
/*   Updated: 2021/12/07 15:38:12 by mberquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char	*dst, const char	*src, size_t	size)
{
	size_t	dst_len;

	dst_len = ft_strlen(dst);
	if (!size || dst_len >= size)
		return (size + ft_strlen(src));
	ft_strlcpy(&dst[dst_len], src, size - dst_len);
	return (dst_len + ft_strlen(src));
}
