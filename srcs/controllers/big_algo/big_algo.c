/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:47:31 by glions            #+#    #+#             */
/*   Updated: 2024/02/26 15:18:14 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	get_target()
{
	
}

static int	ins_cost(t_pile *p, int	target, int mode)
{
	int	pos;
	
	pos = pile_getpos(target, p);
	if (mode == 1)
		return (pos - 1);
	else
		return (pile_size(p) - pos + 1);
}

static int	*ins_cost_all(t_pile *p1, t_pile *p2, int t1, int t2)
{
	int	nb_ins_p1;
	int	nb_ins_p2;
	int	data[4];


	// Total rr
	nb_ins_p1 = ins_cost(p1, t1, 1);
	nb_ins_p2 = ins_cost(p2, t2, 1);
	if (nb_ins_p1 != 0 && nb_ins_p2 != 0)
	{
		if (nb_ins_p1 < nb_ins_p2)
			data[0] = nb_ins_p2;
		else
			data[0] = nb_ins_p1;
		data[1] = 3;
	}
	// Total rrr
	nb_ins_p1 = ins_cost(p1, t1, 2);
	nb_ins_p2 = ins_cost(p2, t2, 2);
	data[2] = 2;
	data[3] = 2;
	if (nb_ins_p1 != 0 && nb_ins_p2 != 0)
	{
		if (nb_ins_p1 < nb_ins_p2 && data[0] > nb_ins_p2)
			data[0] = nb_ins_p2;
		else if (data[0] > nb_ins_p1)
			data[0] = nb_ins_p1;
		data[1] = 4;
	}

	if (nb_ins_p1 > ins_cost(p1, t1, 1))
	{
		nb_ins_p1 = ins_cost(p1, t1, 1);
		data[2] = 1;
	}
	if (nb_ins_p2 > ins_cost(p2, t2, 1))
	{
		nb_ins_p2 = ins_cost(p2, t2, 1);
		data[3] = 1;
	}
	
	if (nb_ins_p1 + nb_ins_p2 < data[0])
		data[0] = nb_ins_p1 + nb_ins_p2;
	else
	{
		data[2] = -1;
		data[3] = -1;
	}
	return (data);
}

static int	get_target(int value, t_pile *p)
{
	t_pile	*tmp;
	int		a;
	int		target;

	tmp = p;
	a = p->value;
	while (tmp)
	{
		if 
		tmp = tmp->next;
	}
}

static	next_moove(t_push_swap *ps, int mode)
{
	t_pile	*p1;
	t_pile	*p2;
	t_pile	*tmp;

	if (mode == 0)
	{
		p1 = ps->pile_a;
		p2 = ps->pile_b;
	}
	else
	{
		p1 = ps->pile_a;
		p2 = ps->pile_b;
	}
}

int	big_algo(t_push_swap *ps)
{
	int	nb_ins;
	int	*sl;

	nb_ins = 0;
	ps_ins_p(ps, 1, 1);
	ps_ins_p(ps, 1, 1);
	nb_ins += 2;
	while (ps->pile_a_s > 3)
		nb_ins += next_moove(ps, 0);
	sl = sort_list(ps->pile_a);
	if (!sl)
		return (NULL);
	nb_ins += small_algo_ps(ps, sl);
	while (ps->pile_b)
		nb_ins += next_moove(ps, 1);
	return (free(sl), nb_ins);
}