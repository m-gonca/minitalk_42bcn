/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogonzal <mogonzal@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 21:32:05 by mogonzal          #+#    #+#             */
/*   Updated: 2022/06/27 19:17:12 by mogonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_find_size(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		count = 11;
	else
	{
		if (n < 0)
		{
			count++;
			n = -n;
		}
		while (n > 9)
		{
			n = n / 10;
			count++;
		}
		count++;
	}
	return (count);
}

int	ft_printint(int n)
{
	char	printnumber;
	int		count;

	count = ft_find_size(n);
	if (n == -2147483648)
	{
		write(1, "-2", 2);
		n = 147483648;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n > 9)
		ft_printint (n / 10);
	printnumber = '0' + n % 10;
	write(1, &printnumber, 1);
	return (count);
}
