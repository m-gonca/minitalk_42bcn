/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogonzal <mogonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 17:27:17 by mogonzal          #+#    #+#             */
/*   Updated: 2022/05/05 13:11:14 by mogonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*	1 -> avanzo los espacios
	2 -> si es signo lo capturo y avanzo 1 (si es negativo sign = -1 else 
	sign = 1)
	3 - > Bucle atoi con la linea magica (cuando llegue al final o encuentra
	 algo que no es un digito hago break y me salgo del bucle)
	4 - > resultado = resultado * signo;
*/

int	ft_isspace(char c)
{
	if (c == ' ')
		return (1);
	if (c == '\t')
		return (1);
	if (c == '\n')
		return (1);
	if (c == '\r')
		return (1);
	if (c == '\v')
		return (1);
	if (c == '\f')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	char	*ptr;
	int		i;
	int		sign;
	int		result;

	ptr = (char *)str;
	i = 0;
	sign = 1;
	result = 0;
	while (ft_isspace(ptr[i]))
		i++;
	if (ptr[i] == '-' || ptr[i] == '+')
	{
		if (ptr[i] == '-')
			sign = -1;
		i++;
	}
	while (ptr[i] >= '0' && ptr[i] <= '9')
	{
		result = (result * 10) + (ptr[i] - '0');
		i++;
	}
	result = result * sign;
	return (result);
}
