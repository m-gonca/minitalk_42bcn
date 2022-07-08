/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogonzal <mogonzal@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 20:22:07 by mogonzal          #+#    #+#             */
/*   Updated: 2022/06/27 19:19:06 by mogonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*	1 -> si es una c o lo que sea, quiero que ejecutes la funcion de conversion
		 de cada tipo con el valor de la variable de la lista que toque y 
		 devuelvas la cantidad de char imprimidos
*/

int	ft_format(char *ptr, va_list argptr)
{
	if (*(ptr + 1) == 'c')
		return (ft_printchar(va_arg(argptr, int)));
	else if (*(ptr + 1) == 's')
		return (ft_printstr(va_arg(argptr, char *)));
	else if (*(ptr + 1) == 'p')
		return (ft_printptr(va_arg(argptr, void *)));
	else if (*(ptr + 1) == 'd' || *(ptr + 1) == 'i' )
		return (ft_printint(va_arg(argptr, int)));
	else if (*(ptr + 1) == 'u' )
		return (ft_printunint(va_arg(argptr, unsigned int)));
	else if (*(ptr + 1) == 'x')
		return (ft_printhexa(va_arg(argptr, unsigned int)));
	else if (*(ptr + 1) == 'X' )
		return (ft_printhexacaps(va_arg(argptr, unsigned int)));
	else if (*(ptr + 1) == '%')
		return (ft_printchar('%'));
	else
		return (ft_printchar(*(ptr + 1)));
	return (0);
}
