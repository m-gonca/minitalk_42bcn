/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogonzal <mogonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 18:30:45 by mogonzal          #+#    #+#             */
/*   Updated: 2022/05/05 15:53:07 by mogonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// como funciona malloc (hipotesis queiro reservar cadena texto de 20)
// char *resultado
// resultado = malloc(sizeof(char) * (20 + 1))
// bucle de relleno resultado[i] con letras hasta llenar los caracteres
// i++
//resultado[i] = '\0'
//Que es Calloc
// 1 - Es hacer un malloc
// 2 - Proteger el malloc por si devuelve NULL
// 3 - Recorrer el espacio de la memoria reservado para llenarlo de 0
// de forma que ahora ese espacio esta formateado sin basura

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(size * count);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, size * count);
	return (ptr);
}
