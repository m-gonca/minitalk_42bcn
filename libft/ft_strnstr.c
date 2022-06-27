/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogonzal <mogonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 18:27:20 by mogonzal          #+#    #+#             */
/*   Updated: 2022/05/13 19:52:51 by mogonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_string(const char *str, const char *needle, size_t len);

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	char	*ptr;

	ptr = (char *)haystack;
	i = 0;
	if (needle[i] == '\0')
		return (ptr);
	if (haystack[0] == '\0' || len < ft_strlen(needle))
		return (NULL);
	while (len > 0 && haystack[i] != '\0')
	{
		if (haystack[i] == needle[0])
		{
			if (ft_check_string(&haystack[i], needle, len) != 0)
				return (&ptr[i]);
		}
		i++;
		len--;
	}
	return (NULL);
}

static int	ft_check_string(const char *str, const char *needle, size_t len)
{	
	size_t	l;
	size_t	count;

	l = 0;
	count = 0;
	while (needle[l] != '\0')
	{
		if (str[l] == needle[l] && len > 0)
			count++;
		l++;
		len--;
	}
	if (count == l)
		return (l);
	return (0);
}
