/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_reverse_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:18:39 by glions            #+#    #+#             */
/*   Updated: 2024/02/29 17:07:39 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	reverse_rotate(t_pile **p)
{
	t_pile	*previous;
	t_pile	*tmp;

	tmp = *p;
	while (tmp->next)
	{
		previous = tmp;
		tmp = tmp->next;
	}
	previous->next = 0;
	tmp->next = *p;
	*p = tmp;
}

void	ins_rr(t_pile **p, int show)
{
	reverse_rotate(p);
	if (show)
	{
		write(1, "rr", 2);
		write(1, &(*p)->id_pile, 1);
		write(1, "\n", 1);
	}
}

void	ins_rr_all(t_pile **p1, t_pile **p2, int show)
{
	reverse_rotate(p1);
	reverse_rotate(p2);
	if (show)
		write(1, "rrr\n", 4);
}
