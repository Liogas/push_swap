/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:10:58 by glions            #+#    #+#             */
/*   Updated: 2024/02/29 18:26:20 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	rotate(t_pile **p)
{
	t_pile	*first;

	if (!*p)
		return ;
	first = *p;
	*p = (*p)->next;
	first->next = NULL;
	pile_addback(p, first);
}

void	ins_r(t_pile **p, int show)
{
	rotate(p);
	if (show)
	{
		write(1, "r", 1);
		write(1, &(*p)->id_pile, 1);
		write(1, "\n", 1);
	}
}

void	ins_r_all(t_pile **p1, t_pile **p2, int show)
{
	rotate(p1);
	rotate(p2);
	if (show)
		write(1, "rr\n", 3);
}
