/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 11:54:35 by mberquer          #+#    #+#             */
/*   Updated: 2022/01/07 10:28:20 by mberquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static	int	ft_count(unsigned long int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		i++;
		n /= 16;
	}
	return (i);
}

static	void	ft_put_hexa(unsigned long int n, const char *base)
{
	if (n / 16 != 0)
		ft_put_hexa(n / 16, base);
	ft_print_char(base[n % 16]);
}

int	ft_print_hexa(unsigned long int n, char f)
{
	const char	*base1 = "0123456789abcdef";
	const char	*base2 = "0123456789ABCDEF";

	if (f == 'x')
	{
		ft_put_hexa(n, base1);
	}
	else if (f == 'X')
	{
		ft_put_hexa(n, base2);
	}
	return (ft_count(n));
}
