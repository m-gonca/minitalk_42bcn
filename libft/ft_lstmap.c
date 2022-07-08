/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogonzal <mogonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 20:01:48 by mogonzal          #+#    #+#             */
/*   Updated: 2022/05/13 19:51:00 by mogonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	while_bucle(t_list *lst, void *(*f)(void *), void (*del)(void *),
	t_list *first_element)
{
	t_list	*new_element;
	void	*temp;

	while (lst)
	{
		temp = f(lst->content);
		new_element = ft_lstnew(temp);
		if (!new_element)
		{
			ft_lstclear(&first_element, del);
			del(temp);
			return (0);
		}
		else
			ft_lstadd_back(&first_element, new_element);
		lst = lst->next;
	}
	return (1);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first_element;
	void	*temp;

	if (!lst || !f)
		return (NULL);
	temp = f(lst->content);
	first_element = ft_lstnew(temp);
	if (!first_element)
	{
		del(temp);
		return (NULL);
	}	
	lst = lst->next;
	if (!while_bucle(lst, f, del, first_element))
		return (NULL);
	return (first_element);
}
