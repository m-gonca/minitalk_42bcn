/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogonzal <mogonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 13:34:33 by mogonzal          #+#    #+#             */
/*   Updated: 2022/05/05 13:22:24 by mogonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*	1 -> calcular el tamano de la cadena donde se guardara el int. mientras 
	el numero sea divisible por 10, suma 1 a count
	2 -> hacer calloc del string donde se guardara y protegerlo
	3 -> asignar cada numero a cada posicion empezando por el final, y teniendo
	cuidado con asignar el - al principio y el caso del numero raro largo
*/

int	ft_find_size(int n)
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

char	*ft_putnumber(int n, char *number, int size)
{
	if (n == -2147483648)
	{
		number[0] = '-';
		number[1] = '2';
		n = 147483648;
	}
	if (n < 0)
	{
		number[0] = '-';
		n = -n;
	}
	while (size > 0 && n > 9)
	{
		number[size - 1] = '0' + n % 10;
		n = n / 10;
		size--;
	}
	number[size - 1] = '0' + n;
	return (number);
}

char	*ft_itoa(int n)
{
	char	*number;
	int		size;

	size = ft_find_size(n);
	number = (char *)ft_calloc((size + 1), sizeof(char));
	if (!number)
		return (NULL);
	return (ft_putnumber(n, number, size));
}
