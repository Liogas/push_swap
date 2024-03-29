/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_addback.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:21:41 by glions            #+#    #+#             */
/*   Updated: 2024/03/28 13:07:13 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	pile_addback(t_pile **pile, t_pile *new)
{
	t_pile	*lst;

	if (!new)
		return (0);
	if (pile_already_in(*pile, new))
		return (0);
	if (!*pile)
		*pile = new;
	else
	{
		lst = *pile;
		while (lst->next)
		{
			lst = lst->next;
		}
		lst->next = new;
	}
	return (1);
}
