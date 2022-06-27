/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogonzal <mogonzal@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:58:44 by mogonzal          #+#    #+#             */
/*   Updated: 2022/04/17 17:11:49 by mogonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	char	*ptr1;
	char	*ptr2;

	ptr1 = (char *)s1;
	ptr2 = (char *)s2;
	if (n == 0)
		return (0);
	while (n > 1)
	{
		if ((*ptr1 != *ptr2) || *ptr1 == '\0')
			return (*(unsigned char *)ptr1 - *(unsigned char *)ptr2);
		ptr1++;
		ptr2++;
		n--;
	}
	if (*ptr1 != *ptr2)
		return (*(unsigned char *)ptr1 - *(unsigned char *)ptr2);
	return (*(unsigned char *)ptr1 - *(unsigned char *)ptr2);
}
