/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogonzal <mogonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:33:06 by mogonzal          #+#    #+#             */
/*   Updated: 2022/05/05 13:34:52 by mogonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*lst2;

	if (lst == NULL)
		return (lst);
	else
	{
		while (lst)
		{	
			lst2 = lst;
			lst = lst->next;
		}
	}
	return (*&lst2);
}
