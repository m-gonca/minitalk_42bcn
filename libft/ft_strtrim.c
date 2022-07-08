/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogonzal <mogonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 18:37:12 by mogonzal          #+#    #+#             */
/*   Updated: 2022/05/05 15:42:04 by mogonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	1 -> casteo los punteros
	2 -> Recorro por la izquierda hasta encontrar un caracter que no este en 
	el set (este es el inicio)
	3 -> Recorro por la derecha hasta encontrar un caracter que no este en el 
	set (este es el final) eliminarla con el substr
	4 -> Recorto con mi substr ahora que ya se inicio y final
*/
char	*ft_strtrim(char const *s1, char const *set)

{
	char	*ptr1;
	char	*result;
	size_t	start;
	size_t	end;
	size_t	count;

	ptr1 = (char *)s1;
	count = 0;
	while (ptr1[count] != '\0' && ft_strchr(set, ptr1[count]))
		count++;
	start = count;
	count = ft_strlen(ptr1);
	while (count > 0 && ft_strchr(set, ptr1[count]))
		count--;
	end = count;
	result = ft_substr(s1, start, end - start + 1);
	return (result);
}
