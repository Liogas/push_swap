/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:47:31 by glions            #+#    #+#             */
/*   Updated: 2024/02/29 16:48:02 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	get_target_a(int value, t_pile *p)
{
	t_pile *tmp;
	int		min;
	int		target;
	int		find;

	tmp = p;
	min = tmp->value;
	find = 0;
	while (tmp)
	{
		if (min > tmp->value)
			min = tmp->value;
		if (tmp->value > value && (find == 0 || tmp->value < target))
		{
			find = 1;
			target = tmp->value;
		}
		tmp = tmp->next;
	}
	if (find)
		return (target);
	return (min);
}

int	get_target_b(int value, t_pile *p)
{
	t_pile *tmp;
	int		max;
	int		target;
	int		find;

	tmp = p;
	max = tmp->value;
	find = 0;
	while (tmp)
	{
		if (max < tmp->value)
			max = tmp->value;
		if (tmp->value < value && (find == 0 || tmp->value > target))
		{
			find = 1;
			target = tmp->value;
		}
		tmp = tmp->next;
	}
	if (find)
		return (target);
	return (max);
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

static int	mooves_p(t_pile **p, int mode)
{
	if (mode == 1)
		ins_r(p, 1);
	else
		ins_rr(p, 1);
	return (1);
}

static int	mooves(t_pile **p1, t_pile **p2, int data[6])
{
	int	nb_ins;

	nb_ins = 0;
	if (data[1] == -1)
	{
		while ((*p1)->value != data[4])
			nb_ins += mooves_p(p1, data[2]);
		while ((*p2)->value != data[5])
			nb_ins += mooves_p(p2, data[3]);
	}
	else
	{
		while ((*p1)->value != data[4] && (*p2)->value != data[5])
		{
			if (data[1] == 3)
				ins_r_all(p1, p2, 1);
			else
				ins_rr_all(p1, p2, 1);
			nb_ins++;
		}
		while ((*p1)->value != data[4])
		{
			ins_r(p1, 1);
			nb_ins++;
		}
		while ((*p2)->value != data[5])
		{
			ins_r(p2, 1);
			nb_ins++;
		}
	}
	return (nb_ins);
}

static int	*init_data(t_pile *p1, t_pile *p2)
{
	int	*data;

	data = malloc(6 * sizeof(int));
	if (!data)
		return (NULL);
	data[0] = 2147483647;
	data[1] = -1;
	data[2] = -1;
	data[3] = -1;
	data[4] = p1->value;
	data[5] = p2->value;
	return (data);
}

static void	update_data(int **data, int value, int target, int *tmp)
{
	(*data)[4] = value;
	(*data)[5] = target;
	(*data)[0] = tmp[0];
	if (tmp[1] != -1)
	{
		(*data)[1] = tmp[1];
		(*data)[2] = -1;
		(*data)[3] = -1;
	}
	else
	{
		(*data)[1] = -1;
		(*data)[2] = tmp[2];
		(*data)[3] = tmp[3];
	}
}

static int	next_moove_b(t_push_swap *ps)
{
	int		target;
	int		*data;
	t_pile	*tmp;
	int		*tmp_data;
	int		nb_ins;

	tmp_data = init_data(ps->pile_b, ps->pile_a);
	if (!tmp_data)
		return (-1);
	tmp = ps->pile_b;
	while (tmp)
	{
		target = get_target_a(tmp->value, ps->pile_a);
		data = get_ins_nb(ps->pile_b, ps->pile_a, tmp->value, target);
		if (!data)
			return (-1);
		if (data[0] < tmp_data[0])
			update_data(&tmp_data, tmp->value, target, data);
		free(data);
		if (tmp_data[0] == 0)
			break;
		tmp = tmp->next;
	}
	nb_ins = mooves(&ps->pile_b, &ps->pile_a, tmp_data) + 1;
	return (ps_ins_p(ps, 1, 2), free(tmp_data), nb_ins);
}

static int	next_moove_a(t_push_swap *ps)
{
	int		target;
	int		*data;
	t_pile	*tmp;
	int		*tmp_data;
	int		nb_ins;

	data = init_data(ps->pile_a, ps->pile_b);
	if (!data)
		return (-1);
	tmp = ps->pile_a;
	while (tmp)
	{
		target = get_target_b(tmp->value, ps->pile_b);
		tmp_data = get_ins_nb(ps->pile_a, ps->pile_b, tmp->value, target);
		if (!tmp_data)
			return (-1);
		if (tmp_data[0] < data[0])
			update_data(&data, tmp->value, target, tmp_data);
		free(tmp_data);
		if (data[0] == 0)
			break;
		tmp = tmp->next;
	}
	nb_ins = mooves(&ps->pile_a, &ps->pile_b, data) + 1;
	return (ps_ins_p(ps, 1, 1), free(data), nb_ins);
}

static int	get_min_pile(t_pile *p)
{
	int		min;
	t_pile	*tmp;

	min = p->value;
	tmp = p;
	while (tmp)
	{
		if (tmp->value < min)
			min = tmp->value;
		tmp = tmp->next;
	}
	return (min);
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
		nb_ins += next_moove_a(ps);
	sl = sort_list(ps->pile_a);
	if (!sl)
		return (-1);
	nb_ins += small_algo_ps(ps, sl);
	while (ps->pile_b)
		nb_ins += next_moove_b(ps);
	nb_ins += last_moove(&ps->pile_a);
	return (free(sl), nb_ins);
}
