/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_addback.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:21:41 by glions            #+#    #+#             */
/*   Updated: 2024/02/19 16:26:39 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	pile_addback(t_pile **pile, t_pile *new)
{
	t_pile	*lst;

	if (!new)
		return (0);
	if (!*pile)
		*pile = new;
	else
	{
		lst = *pile;
		while (lst->next)
		{
			if (lst->value == new->value)
				return (0);
			lst = lst->next;
		}
		lst->next = new;
	}
	return (1);
}
