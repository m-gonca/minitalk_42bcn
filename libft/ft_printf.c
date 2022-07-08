/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogonzal <mogonzal@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 13:05:01 by mogonzal          #+#    #+#             */
/*   Updated: 2022/06/27 19:16:54 by mogonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *s, ...)
{
	va_list		argptr;
	size_t		i;
	int			printed;

	va_start(argptr, s);
	i = 0;
	printed = 0;
	if (!*s)
		return (printed);
	while (i < ft_strlen(s))
	{
		if (s[i] == '%')
		{
			printed = printed + ft_format(&((char *)s)[i], argptr);
			i = i + 2;
		}
		else
		{
			printed = printed + ft_printchar(s[i]);
			i++;
		}
	}
	va_end(argptr);
	return (printed);
}
