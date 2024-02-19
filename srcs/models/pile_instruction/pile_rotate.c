/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:10:58 by glions            #+#    #+#             */
/*   Updated: 2024/02/19 16:27:38 by glions           ###   ########.fr       */
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

void	rotate_a(t_pile **pa, int show)
{
	rotate(pa);
	if (show)
		write(1, "ra\n", 3);
}

void	rotate_b(t_pile **pb, int show)
{
	rotate(pb);
	if (show)
		write(1, "rb\n", 3);
}

void	rotate_rr(t_pile **pa, t_pile **pb, int show)
{
	rotate(pa);
	rotate(pb);
	if (show)
		write(1, "rr\n", 3);
}
