/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogonzal <mogonzal@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 17:32:17 by mogonzal          #+#    #+#             */
/*   Updated: 2022/06/27 19:17:01 by mogonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printhexa(unsigned int n)
{
	char	*base;
	int		count;

	count = 0;
	base = "0123456789abcdef";
	if (n > 15)
	{
		count = count + ft_printhexa(n / 16);
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
