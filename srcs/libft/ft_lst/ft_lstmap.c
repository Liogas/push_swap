/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:46:18 by glions            #+#    #+#             */
/*   Updated: 2024/01/19 23:45:23 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void	create_newlst(t_list **l, void *content,
	t_list *new_lst, void (*del)(void *))
{
	*l = ft_lstnew(content);
	if (!(*l))
	{
		ft_lstclear(&new_lst, del);
		*l = NULL;
		return ;
	}
	ft_lstadd_back(&new_lst, *l);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	void	*new_content;
	t_list	*tmp;

	new_lst = NULL;
	while (lst && f && del)
	{
		new_content = f(lst->content);
		if (!new_lst)
		{
			new_lst = ft_lstnew(new_content);
			if (!new_lst)
				return (NULL);
		}
		else
		{
			create_newlst(&tmp, new_content, new_lst, del);
			if (!tmp)
				return (NULL);
		}
		lst = lst->next;
	}
	return (new_lst);
}
