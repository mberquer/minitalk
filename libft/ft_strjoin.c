/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 12:43:12 by mberquer          #+#    #+#             */
/*   Updated: 2021/12/17 16:59:20 by mberquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;

	if (s1 && s2)
	{
		s3 = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
		if (!s3)
			return (NULL);
		ft_strlcpy(s3, s1, ft_strlen(s1) + 1);
		ft_strlcat(s3, s2, ft_strlen(s3) + ft_strlen(s2) + 1);
		return (s3);
	}
	return (NULL);
}
