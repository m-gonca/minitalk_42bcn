/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogonzal <mogonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:16:51 by mogonzal          #+#    #+#             */
/*   Updated: 2022/05/13 18:52:18 by mogonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	char	*s1;
	size_t	i;

	s1 = (char *)s;
	i = 0;
	if (start >= ft_strlen(s) || len == 0 || s == 0)
	{	
		ptr = ft_calloc(1, 1);
		if (!ptr)
			return (NULL);
		return (ptr);
	}
	if ((ft_strlen(s) - start) < len)
		len = ft_strlen(s) - start;
	ptr = (char *)ft_calloc(1, (len + 1));
	if (!ptr)
		return (NULL);
	while (i < len && s1[start])
	{
		ptr[i] = s1[start];
		i++;
		start++;
	}
	return (ptr);
}
