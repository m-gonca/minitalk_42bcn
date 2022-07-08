/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogonzal <mogonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 17:05:29 by mogonzal          #+#    #+#             */
/*   Updated: 2022/05/05 15:37:15 by mogonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	1 -> casteo los punteros
	2 -> hago malloc de la suma de los dos strings
	3 -> mientras len > 0 hago memmove de un string y depues del otro
	4 -> devuelvo el puntero
*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr1;
	char	*ptr2;
	char	*ptr3;
	int		len;

	ptr1 = (char *)s1;
	ptr2 = (char *)s2;
	len = ft_strlen(s1) + ft_strlen(s2);
	ptr3 = (char *)ft_calloc(1, (len + 1));
	if (!ptr3)
		return (NULL);
	ft_memmove(ptr3, ptr1, ft_strlen(s1));
	ft_memmove(ptr3 + ft_strlen(s1), ptr2, ft_strlen(s2));
	return (ptr3);
}
