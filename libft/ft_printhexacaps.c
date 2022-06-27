/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexacaps.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogonzal <mogonzal@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 17:32:17 by mogonzal          #+#    #+#             */
/*   Updated: 2022/05/19 13:08:42 by mogonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhexacaps(unsigned int n)
{
	char	*base;
	int		count;

	count = 0;
	base = "0123456789ABCDEF";
	if (n > 15)
	{
		count = count + ft_printhexacaps(n / 16);
		write (1, &base[n % 16], 1);
		count++;
	}
	if (n <= 15)
	{
		write (1, &base[n], 1);
		count++;
	}
	return (count);
}
