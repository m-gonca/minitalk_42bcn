/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogonzal <mogonzal@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 21:27:23 by mogonzal          #+#    #+#             */
/*   Updated: 2022/05/19 13:09:36 by mogonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
	1-> habra que dividir el numero por la base, hasta que no se pueda dividir 
	mas, en cuyo caso el resto de la division anterior sera el cociente de la 
	ultima operacion. Esto se hace haciendo una recursion de la funcion dividi
	diendo por 16
	2-> Se dividira hasta que el ultimo cociente sea menor de 16, y se imrpimi
	ra en base 16 (string con la base)
	3-> Despues se iran imprimiendo los restos de cada division de forma recur
	siva, y tambien usando la base 16 
*/

static int	ft_addr_hexa(unsigned long long addr)
{
	char	*base;
	int		count;

	count = 0;
	base = "0123456789abcdef";
	if (addr > 15)
	{
		count = count + ft_addr_hexa(addr / 16);
		if (write (1, &base[addr % 16], 1) == -1)
			return (-1);
		count++;
	}
	if (addr <= 15)
	{
		if (write (1, &base[addr], 1) == -1)
			return (-1);
		count++;
	}
	return (count);
}

int	ft_printptr(void *addr)
{
	int	count;

	write (1, "0x", 2);
	count = 2 + ft_addr_hexa((unsigned long long)addr);
	return (count);
}
