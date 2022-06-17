/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:15:20 by mberquer          #+#    #+#             */
/*   Updated: 2022/01/07 10:30:41 by mberquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(unsigned long int p)
{
	int	len;

	len = 2;
	ft_print_str("0x");
	len += ft_print_hexa(p, 'x');
	return (len);
}
