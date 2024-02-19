/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:26:05 by glions            #+#    #+#             */
/*   Updated: 2024/02/19 16:26:21 by glions           ###   ########.fr       */
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

void	swap_a(t_pile **p, int show)
{
	swap(p);
	if (show)
		write(1, "sa\n", 3);
}

void	swap_b(t_pile **p, int show)
{
	swap(p);
	if (show)
		write(1, "sb\n", 3);
}

void	swap_ss(t_pile **pa, t_pile **pb, int show)
{
	swap_a(pa, 0);
	swap_b(pb, 0);
	if (show)
		write(1, "ss\n", 3);
}
