/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 10:28:42 by mberquer          #+#    #+#             */
/*   Updated: 2022/01/07 10:30:18 by mberquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_count(int n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

static void	ft_put_nbr(int n)
{
	long int	n2;

	n2 = (long int)n;
	if (n2 < 0)
	{
		ft_print_char('-');
		n2 *= -1;
	}
	if (n2 / 10 != 0)
		ft_put_nbr(n2 / 10);
	ft_print_char((n2 % 10) + 48);
}

int	ft_print_nbr(int n)
{
	int	i;

	i = ft_count(n);
	ft_put_nbr(n);
	return (i);
}
