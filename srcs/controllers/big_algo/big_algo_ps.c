/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo_ps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:41:46 by glions            #+#    #+#             */
/*   Updated: 2024/02/22 20:13:03 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	get_target(t_pile *p1, t_pile *p2)
{
	int		target;
	int		min;
	int		find;
	t_pile	*tmp;

	find = 0;
	min = p2->value;
	tmp = p2;
	while (tmp)
	{
		if (p1->value < tmp->value &&
			(find == 0 || (find == 1 && tmp->value < target)))
			{
				target = tmp->value;
				find = 1;
			}
		if (tmp->value < min)
			min = tmp->value;
		tmp = tmp->next;
	}
	if (!find)
		return (min);	
	return (target);
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

static int	nb_ins_top(int target, int mode, t_pile *p)
{
	t_pile *tmp;
	int		i;

	tmp = pile_dup(p);
	if (!tmp)
		return (999999);
	i = 0;
	while (tmp->value != target)
	{
		if (mode == 1)
			ins_r(&tmp, 0);
		else if (mode == 2)
			ins_rr(&tmp, 0);
		i++;
	}
	pile_free(tmp);
	return (i);
}

static int	next_moove(t_pile **p1, t_pile **p2)
{
	int	target;
	int	nb_ins;

	target = get_target(*p1, *p2);
	nb_ins = 0;
	while ((*p2)->value != target)
	{
		if (nb_ins_top(target, 1, *p2) <= nb_ins_top(target, 1, *p2))
			ins_r(p2, 1);
		else
			ins_rr(p2, 1);
		nb_ins++;
	}
	ins_p(p1, p2, 1);
	return (nb_ins + 1);
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
		if (nb_ins_top(target, 1, *p) < nb_ins_top(target, 2, *p))
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

int	big_algo_ps(t_push_swap *ps)
{
	int	nb_ins;
	int	*sl2;
	int	tmp;

	nb_ins = 0;
	ins_p(&ps->pile_a, &ps->pile_b, 1);
	ins_p(&ps->pile_a, &ps->pile_b, 1);
	nb_ins += 2;
	while (pile_size(ps->pile_a) > 3)
		nb_ins += next_moove(&ps->pile_a, &ps->pile_b);
	sl2 = sort_list(ps->pile_a);
	if (!sl2)
		return (-1);
	tmp = small_algo_ps(ps, sl2);
	if (tmp == -1)
		return (free(sl2), (-1));
	nb_ins += tmp;
	while (pile_size(ps->pile_b) > 0)
		nb_ins += next_moove(&ps->pile_b, &ps->pile_a);
	free(sl2);
	nb_ins += last_moove(&ps->pile_a);
    return (nb_ins);
}
