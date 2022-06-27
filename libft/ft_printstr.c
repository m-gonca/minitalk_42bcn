/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogonzal <mogonzal@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 20:50:06 by mogonzal          #+#    #+#             */
/*   Updated: 2022/05/19 13:09:49 by mogonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstr(char *s)
{
	int	count;

	if (s == NULL)
		return (ft_printstr("(null)"));
	count = ft_strlen(s);
	while (*s)
	{
		write(1, s, 1);
		s++;
	}
	return (count);
}
