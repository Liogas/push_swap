/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:47:31 by glions            #+#    #+#             */
/*   Updated: 2024/02/27 14:50:54 by glions           ###   ########.fr       */
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

static int	*ins_cost_all(t_pile *p1, t_pile *p2, int t1, int t2)
{
	int	nb_ins_p1;
	int	nb_ins_p2;
	int	*data;

	data = malloc(4 * sizeof(int));
	if (!data)
		return (NULL);
	// Total rr
	nb_ins_p1 = ins_cost(p1, t1, 1);
	nb_ins_p2 = ins_cost(p2, t2, 1);
	data[0] = 2147483647;
	data[1] = -1;
	data[2] = -1;
	data[3] = -1;
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
	{
		data[1] = -1;
		data[0] = nb_ins_p1 + nb_ins_p2;
	}
	else
	{
		data[2] = -1;
		data[3] = -1;
	}
	return (data);
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
		while ((*p1)->value != data[5])
			nb_ins += mooves_p(p1, data[2]);
		while ((*p2)->value != data[4])
			nb_ins += mooves_p(p2, data[3]);
	}
	return (nb_ins);
}

static int	next_moove_b(t_push_swap *ps)
{
	int		target;
	// t_pile	*winner;
	int		*data;
	t_pile	*tmp;
	int		tmp_data[6];
	int		nb_ins;

	tmp_data[0] = 2147483647;
	tmp_data[1] = -1;
	tmp_data[2] = -1;
	tmp_data[3] = -1;
	tmp_data[4] = ps->pile_a->value;
	tmp = ps->pile_b;
	tmp_data[5] = tmp->value;
	while (tmp)
	{
		target = get_target_a(tmp->value, ps->pile_a);
		printf("target de %d->%d\n", tmp->value, target);
		data = ins_cost_all(ps->pile_b, ps->pile_a, tmp->value, target);
		if (!data)
			return (printf("Erreur data\n"), (-1));
		printf("ins->%d;mode->%d;a->%d;b->%d\n", data[0], data[1], data[2], data[3]);
		if (data[0] < tmp_data[0])
		{
			tmp_data[5] = tmp->value;
			tmp_data[4] = target;
			tmp_data[0] = data[0];
			if (data[1] != -1)
				tmp_data[1] = data[1];
			else
			{
				tmp_data[2] = data[2];
				tmp_data[3] = data[3];
			}
		}
		free(data);
		tmp = tmp->next;
	}
	printf("Resultat final= tmp_data[0]->%d tmp_data[1]->%d tmp_data[2]->%d tmp_data[3]->%d tmp_data[4]->%d tmp_data[5]->%d\n", tmp_data[0], tmp_data[1], tmp_data[2], tmp_data[3], tmp_data[4], tmp_data[5]);
	nb_ins = mooves(&ps->pile_b, &ps->pile_a, tmp_data) + 1;
	ps_ins_p(ps, 1, 2);
	return (nb_ins);
}

static int	next_moove_a(t_push_swap *ps)
{
	int		target;
	// t_pile	*winner;
	int		*data;
	t_pile	*tmp;
	int		tmp_data[6];
	int		nb_ins;

	tmp_data[0] = 2147483647;
	tmp_data[1] = -1;
	tmp_data[2] = -1;
	tmp_data[3] = -1;
	tmp_data[4] = ps->pile_b->value;
	tmp = ps->pile_a;
	tmp_data[5] = tmp->value;
	while (tmp)
	{
		target = get_target_b(tmp->value, ps->pile_b);
		printf("target de %d->%d\n", tmp->value, target);
		data = ins_cost_all(ps->pile_a, ps->pile_b, tmp->value, target);
		if (!data)
			return (printf("Erreur data\n"), (-1));
		printf("ins->%d;mode->%d;a->%d;b->%d\n", data[0], data[1], data[2], data[3]);
		if (data[0] < tmp_data[0])
		{
			tmp_data[5] = tmp->value;
			tmp_data[4] = target;
			tmp_data[0] = data[0];
			if (data[1] != -1)
				tmp_data[1] = data[1];
			else
			{
				tmp_data[2] = data[2];
				tmp_data[3] = data[3];
			}
		}
		free(data);
		tmp = tmp->next;
	}
	printf("Resultat final= tmp_data[0]->%d tmp_data[1]->%d tmp_data[2]->%d tmp_data[3]->%d tmp_data[4]->%d tmp_data[5]->%d\n", tmp_data[0], tmp_data[1], tmp_data[2], tmp_data[3], tmp_data[4], tmp_data[5]);
	nb_ins = mooves(&ps->pile_a, &ps->pile_b, tmp_data) + 1;
	ps_ins_p(ps, 1, 1);
	return (nb_ins);
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
		{
			ins_r(p, 1);
			i++;
		}
		else
		{
			ins_rr(p, 1);
			i++;
		}
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
	{
		nb_ins += next_moove_a(ps);
		printf("nb_ins->%d\n", nb_ins);
		printf("Etat de mes piles apres modif\n");
		pile_show(ps->pile_a);
		printf("\n\n\n");
		pile_show(ps->pile_b);
	}
	sl = sort_list(ps->pile_a);
	if (!sl)
		return (-1);
	nb_ins += small_algo_ps(ps, sl);
	printf("Etat de mes piles apres petit algo\n");
	pile_show(ps->pile_a);
	printf("\n\n\n");
	pile_show(ps->pile_b);
	while (ps->pile_b)
	{
		nb_ins += next_moove_b(ps);
		printf("nb_ins->%d\n", nb_ins);
		printf("Etat de mes piles apres modif\n");
		pile_show(ps->pile_a);
		printf("\n\n\n");
		pile_show(ps->pile_b);
	}
	nb_ins += last_moove(&ps->pile_a);
	printf("Etat de mes piles apres modif\n");
	pile_show(ps->pile_a);
	return (free(sl), nb_ins);
}