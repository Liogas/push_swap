/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:26:05 by glions            #+#    #+#             */
/*   Updated: 2024/02/22 19:02:07 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	swap(t_pile **p)
{
	t_pile	*first;
	t_pile	*second;
	t_pile	*tmp;

	first = *p;
	if (first)
		second = first->next;
	else
		return ;
	if (second)
		tmp = second->next;
	else
		return ;
	second->next = first;
	first->next = tmp;
	*p = second;
}

void	ins_s(t_pile **p, int show)
{
	swap(p);
	if (show)
	{
		write(1, "s", 1);
		write(1, &(*p)->id_pile, 1);
		write(1, "\n", 1);
	}
}
void	ins_s_all(t_pile **p1, t_pile **p2, int show)
{
	swap(p1);
	swap(p2);
	if (show)
		write(1, "ss\n", 3);
}
