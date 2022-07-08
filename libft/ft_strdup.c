/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogonzal <mogonzal@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 18:56:08 by mogonzal          #+#    #+#             */
/*   Updated: 2022/04/18 21:20:36 by mogonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*char *palabra;
palabra = malloc(sizeof(char) * (4 + 1));
if(!palabra)
	return(NULL);
palabra[0] = 'h';
palabra[1] = 'o';
palabra[2] = 'l';
palabra[3] = 'a';
palabra[4] = '\0';

es lo mismo que:
palabra = ft_strdup("hola");
*/

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	char	*s2;

	s2 = (char *)s1;
	ptr = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!ptr)
		return (NULL);
	ptr = ft_memcpy(ptr, s2, (ft_strlen(s1)+1));
	return (ptr);
}
