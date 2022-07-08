/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogonzal <mogonzal@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 17:33:48 by mogonzal          #+#    #+#             */
/*   Updated: 2022/04/17 17:00:51 by mogonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		l;
	char	*ptr;

	ptr = (char *)s;
	l = ft_strlen(s);
	while (l >= 0)
	{
		if (ptr[l] == (unsigned char)c)
			return (&ptr[l]);
		l--;
	}
	return (NULL);
}
