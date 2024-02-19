/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_reverse_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:18:39 by glions            #+#    #+#             */
/*   Updated: 2024/02/19 16:27:41 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	reverse_rotate(t_pile **p)
{
	t_pile	*last;
	t_pile	*previous;

	last = *p;
	previous = NULL;
	while (last->next)
	{
		previous = last;
		last = last->next;
	}
	if (previous)
		previous->next = NULL;
	last->next = *p;
	*p = last;
}

void	reverse_rotate_a(t_pile **pa, int show)
{
	reverse_rotate(pa);
	if (show)
		write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_pile **pb, int show)
{
	reverse_rotate(pb);
	if (show)
		write(1, "rrb\n", 4);
}

void	reverse_rotate_rrr(t_pile **pa, t_pile **pb, int show)
{
	reverse_rotate(pa);
	reverse_rotate(pb);
	if (show)
		write(1, "rrr\n", 4);
}
