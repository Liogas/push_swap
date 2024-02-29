/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ins_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:11:44 by glions            #+#    #+#             */
/*   Updated: 2024/02/29 18:25:43 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ins_cost(t_pile *p, int target, int mode)
{
	int	pos;

	pos = pile_getpos(target, p);
	if (mode == 1)
		return (pos - 1);
	else
		return (pile_size(p) - pos + 1);
}

int	get_ins_rrr(t_pile *p1, t_pile *p2, int t1, int t2)
{
	int	ins_p1;
	int	ins_p2;

	ins_p1 = ins_cost(p1, t1, 2);
	ins_p2 = ins_cost(p2, t2, 2);
	if (ins_p1 == 0 || ins_p2 == 0)
		return (-1);
	if (ins_p1 < ins_p2)
		return (ins_p2);
	else
		return (ins_p1);
}

int	get_ins_rr(t_pile *p1, t_pile *p2, int t1, int t2)
{
	int	ins_p1;
	int	ins_p2;

	ins_p1 = ins_cost(p1, t1, 1);
	ins_p2 = ins_cost(p2, t2, 1);
	if (ins_p1 == 0 || ins_p2 == 0)
		return (-1);
	if (ins_p1 < ins_p2)
		return (ins_p2);
	else
		return (ins_p1);
}
