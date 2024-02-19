/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:57:04 by glions            #+#    #+#             */
/*   Updated: 2024/02/19 16:27:27 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	push(t_pile **p1, t_pile **p2)
{
	t_pile	*first;

	if (!*p1)
		return ;
	first = *p1;
	*p1 = (*p1)->next;
	first->next = *p2;
	*p2 = first;
}

void	push_a(t_pile **pb, t_pile **pa, int show)
{
	push(pb, pa);
	if (show)
		write(1, "pa\n", 3);
}

void	push_b(t_pile **pa, t_pile **pb, int show)
{
	push(pa, pb);
	if (show)
		write(1, "pb\n", 3);
}
