/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:57:04 by glions            #+#    #+#             */
/*   Updated: 2024/02/26 13:49:53 by glions           ###   ########.fr       */
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
	if ((*p2)->id_pile == 'a')
		(*p2)->id_pile = 'b';
	else
		(*p2)->id_pile = 'a';
}

void	ins_p(t_pile **p_src, t_pile **p_dest, int show)
{
	push(p_src, p_dest);
	if (show)
	{
		write(1, "p", 1);
		write(1, &(*p_dest)->id_pile, 1);
		write(1, "\n", 1);
	}
}

void	ps_ins_p(t_push_swap *ps, int show, int mode)
{
	if (mode == 1)
		ins_p(&ps->pile_a, &ps->pile_b, show);
	else
		ins_p(&ps->pile_b, &ps->pile_a, show);
	push_swap_update_size(ps);
}
