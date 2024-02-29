/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:47:31 by glions            #+#    #+#             */
/*   Updated: 2024/02/29 18:23:30 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	mooves(t_pile **p1, t_pile **p2, int data[6])
{
	if (data[1] == -1)
	{
		while ((*p1)->value != data[4])
			mooves_p(p1, data[2]);
		while ((*p2)->value != data[5])
			mooves_p(p2, data[3]);
	}
	else
	{
		while ((*p1)->value != data[4] && (*p2)->value != data[5])
		{
			if (data[1] == 3)
				ins_r_all(p1, p2, 1);
			else
				ins_rr_all(p1, p2, 1);
		}
		while ((*p1)->value != data[4])
			ins_r(p1, 1);
		while ((*p2)->value != data[5])
			ins_r(p2, 1);
	}
}

static int	next_moove_b(t_push_swap *ps)
{
	int		target;
	int		*data;
	t_pile	*tmp;
	int		*tmp_data;

	tmp_data = init_data(ps->pile_b, ps->pile_a);
	if (!tmp_data)
		return (0);
	tmp = ps->pile_b;
	while (tmp)
	{
		target = get_target_a(tmp->value, ps->pile_a);
		data = get_ins_nb(ps->pile_b, ps->pile_a, tmp->value, target);
		if (!data)
			return (0);
		if (data[0] < tmp_data[0])
			update_data(&tmp_data, tmp->value, target, data);
		free(data);
		if (tmp_data[0] == 0)
			break ;
		tmp = tmp->next;
	}
	mooves(&ps->pile_b, &ps->pile_a, tmp_data);
	return (ps_ins_p(ps, 1, 2), free(tmp_data), 1);
}

static int	next_moove_a(t_push_swap *ps)
{
	int		target;
	int		*data;
	t_pile	*tmp;
	int		*tmp_data;

	data = init_data(ps->pile_a, ps->pile_b);
	if (!data)
		return (0);
	tmp = ps->pile_a;
	while (tmp)
	{
		target = get_target_b(tmp->value, ps->pile_b);
		tmp_data = get_ins_nb(ps->pile_a, ps->pile_b, tmp->value, target);
		if (!tmp_data)
			return (0);
		if (tmp_data[0] < data[0])
			update_data(&data, tmp->value, target, tmp_data);
		free(tmp_data);
		if (data[0] == 0)
			break ;
		tmp = tmp->next;
	}
	mooves(&ps->pile_a, &ps->pile_b, data);
	return (ps_ins_p(ps, 1, 1), free(data), 1);
}

static int	last_moove(t_pile **p)
{
	int	i;
	int	target;

	target = get_min_pile(*p);
	if ((*p)->value == target)
		return (0);
	i = 0;
	while ((*p)->value != target)
	{
		if (ins_cost(*p, target, 1) < ins_cost(*p, target, 2))
			ins_r(p, 1);
		else
			ins_rr(p, 1);
		i++;
	}
	return (i);
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
		next_moove_a(ps);
	sl = sort_list(ps->pile_a);
	if (!sl)
		return (0);
	nb_ins += small_algo_ps(ps, sl);
	while (ps->pile_b)
		next_moove_b(ps);
	last_moove(&ps->pile_a);
	return (free(sl), 1);
}
