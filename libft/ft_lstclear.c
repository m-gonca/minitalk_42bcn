/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogonzal <mogonzal@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 19:01:38 by mogonzal          #+#    #+#             */
/*   Updated: 2022/05/02 20:01:12 by mogonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*lst1;
	t_list	*element;

	if (!del || !lst || !*lst)
		return ;
	element = lst[0];
	while (element)
	{
		lst1 = element->next;
		ft_lstdelone(element, del);
		element = lst1;
	}
	lst[0] = NULL;
}
