/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogonzal <mogonzal@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 21:32:05 by mogonzal          #+#    #+#             */
/*   Updated: 2022/06/27 19:17:24 by mogonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_find_size(unsigned int n)
{
	int	count;

	count = 0;
	while (n > 9)
	{
			n = n / 10;
			count++;
	}
	count++;
	return (count);
}

int	ft_printunint(unsigned int n)
{
	char	printnumber;

	if (n > 9)
		ft_printunint (n / 10);
	printnumber = '0' + n % 10;
	write(1, &printnumber, 1);
	return (ft_find_size(n));
}
