/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo_ps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:41:46 by glions            #+#    #+#             */
/*   Updated: 2024/02/23 20:02:02 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	get_target(t_pile *p1, t_pile *p2)
{
	int		target;
	int		min;
	int		find;
	t_pile	*tmp;

	// printf("Entrée dans get_target avec %d\n", p1->value);
	find = 0;
	min = p2->value;
	tmp = p2;
	while (tmp)
	{
		// printf("tmp->%d\n",tmp->value);
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
	// printf("FIND->%d\n", find);
	if (find == 0)
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

static int	ins_nb_top(int target, int mode, t_pile *p)
{
	int		pos;

	pos = pile_getpos(target, p);
	if (mode == 1)
		return (pos - 1);
	else
		return ((pile_size(p) + 1) - pos);
}

static int	ins_same(int target[2], int mode, t_pile *p1, t_pile *p2)
{
	int	ins_p1;
	int	ins_p2;
	int	ins_tot;

	ins_p1 = ins_nb_top(target[0], mode, p1);
	ins_p2 = ins_nb_top(target[1], mode, p2);
	ins_tot = ins_p1 - ins_p2;
	if (ins_tot < 0)
		ins_tot = (ins_tot * -1) + ins_p1;
	else
		ins_tot += ins_p2;
	return (ins_tot);
}
static int	get_ins_nb(int t1, int t2, t_pile *p1, t_pile *p2)
{
	int	ins_nb;
	int	targets[2];

	ins_nb = ins_nb_top(t1, 1, p1) + ins_nb_top(t2, 1, p2);
	targets[0] = t1;
	targets[1] = t2;
	if (ins_nb_top(t1, 1, p1) + ins_nb_top(t2, 2, p2) < ins_nb)
		ins_nb = ins_nb_top(t1, 1, p1) + ins_nb_top(t2, 2, p2);
	if (ins_nb_top(t1, 2, p1) + ins_nb_top(t2, 1, p2) < ins_nb)
		ins_nb = ins_nb_top(t1, 2, p1) + ins_nb_top(t2, 1, p2);
	if (ins_nb_top(t1, 2, p1) + ins_nb_top(t2, 2, p2) < ins_nb)
		ins_nb = ins_nb_top(t1, 2, p1) + ins_nb_top(t2, 2, p2);
	if (ins_same(targets, 1, p1, p2) < ins_nb)
		ins_nb = ins_same(targets, 1, p1, p2);
	if (ins_same(targets, 2, p1, p2) < ins_nb)
		ins_nb = ins_same(targets, 2, p1, p2);
	return (ins_nb);
}

static int	*get_ins_mode(int t1, int t2, t_pile *p1, t_pile *p2)
{
	int	ins_nb;
	int	targets[2];
	int	*mode;

	mode = malloc(2 * sizeof(int));
	if (!mode)
		return (NULL);
	ins_nb = ins_nb_top(t1, 1, p1) + ins_nb_top(t2, 1, p2);
	mode[0] = 0;
	mode[1] = 0;
	targets[0] = t1;
	targets[1] = t2;
	if (ins_nb_top(t1, 1, p1) + ins_nb_top(t2, 2, p2) < ins_nb)
	{
		ins_nb = ins_nb_top(t1, 1, p1) + ins_nb_top(t2, 2, p2);
		mode[1] = 1;
	}
	if (ins_nb_top(t1, 2, p1) + ins_nb_top(t2, 1, p2) < ins_nb)
	{
		ins_nb = ins_nb_top(t1, 2, p1) + ins_nb_top(t2, 1, p2);
		mode[0] = 1;
		mode[1] = 0; 
	}
	if (ins_nb_top(t1, 2, p1) + ins_nb_top(t2, 2, p2) < ins_nb)
	{
		ins_nb = ins_nb_top(t1, 2, p1) + ins_nb_top(t2, 2, p2);
		mode[0] = 1;
		mode[1] = 1;
	}
	if (ins_same(targets, 1, p1, p2) < ins_nb)
	{
		ins_nb = ins_same(targets, 1, p1, p2);
		mode[0] = 2;
	}
	if (ins_same(targets, 2, p1, p2) < ins_nb)
	{
		ins_nb = ins_same(targets, 2, p1, p2);
		mode[0] = 3;
	}
	return (mode);
}

static void	mooves_p(t_pile **p, int t, int mode)
{
	while ((*p)->value != t)
	{
		if (mode == 0)
			ins_r(p, 1);
		else
			ins_rr(p, 1);
	}
}

static void	mooves(int t1, int t2, t_pile **p1, t_pile **p2)
{
	int		*mode;

	// printf("Entrée dans mooves\n");
	mode = get_ins_mode(t1, t2, *p1, *p2);
	// printf("Target(p1)->%d;Target(p2)->%d\n", t1, t2);
	if (!mode)
		return ;
	if (mode[0] == 0 || mode[0] == 1)
		(mooves_p(p1, t1, mode[1]), mooves_p(p2, t2, mode[1]));
	else if (mode[0] == 2 || mode[0] == 3)
	{
		while ((*p1)->value != t1 && (*p2)->value != t2)
		{
			if (mode[0] == 3)
				ins_r_all(p1, p2, 1);
			else
				ins_rr_all(p1, p2, 1);
		}
		if (ins_nb_top(t1, 1, *p1) != 0)
		{
			if (ins_nb_top(t1, 1, *p1) < ins_nb_top(t1, 2, *p1))
				mooves_p(p1, t1, 0);
			else
				mooves_p(p1, t1, 1);
		}	
		else
		{
			if (ins_nb_top(t2, 1, *p2) < ins_nb_top(t2, 2, *p2))
				mooves_p(p2, t2, 0);
			else
				mooves_p(p2, t2, 1);
		}
	}
	// printf("Sortie de mooves\n");
	free(mode);
}

static int	next_moove(t_push_swap *ps, int mode)
{
	t_pile	*p1;
	t_pile	*p2;
	t_pile	*tmp;
	t_pile	*winner;
	long	ins_min;
	int		target;
	int		target_b;
	int		ins_nb;

	if (mode == 0)
	{
		p1 = ps->pile_a;
		p2 = ps->pile_b;
	}
	else
	{
		p1 = ps->pile_b;
		p2 = ps->pile_a;
	}
	ins_min = 2147483647;
	tmp = p1;
	while (tmp)
	{
		target = get_target(tmp, p2);
		// printf("target(tmp->%d)->%d\n", tmp->value, target);
		ins_nb = get_ins_nb(tmp->value, target, p1, p2);
		// printf("Nombre de coups->%d\n", ins_nb);
		if (ins_nb < ins_min)
		{
			target_b = target;
			winner = tmp;
			if (ins_nb == 0)
				break;
			ins_min = ins_nb;
		}
		tmp = tmp->next;
	}
	if (mode == 0)
		mooves(winner->value, target_b, &ps->pile_a, &ps->pile_b);
	else
		mooves(winner->value, target_b, &ps->pile_b, &ps->pile_a);
	return (ps_ins_p(ps, 1, mode), ins_min);
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
		if (ins_nb_top(target, 1, *p) < ins_nb_top(target, 2, *p))
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

	// printf("Entrée dans l'algo\n");
	nb_ins = 0;
	ps_ins_p(ps, 1, 0);
	ps_ins_p(ps, 1, 0);
	// printf("Etape 1 finie\n");
	nb_ins += 2;
	while (ps->pile_a_s > 3)
	{
		nb_ins += next_moove(ps, 0);
		// printf("Liste a\n");
		// pile_show(ps->pile_a);
		// printf("Liste b\n");
		// pile_show(ps->pile_b);
	}
	// printf("Etape 2 finie\n");
	sl2 = sort_list(ps->pile_a);
	if (!sl2)
		return (-1);
	tmp = small_algo_ps(ps, sl2);
	// printf("Etape 3 finie\n");
	if (tmp == -1)
		return (free(sl2), (-1));
	nb_ins += tmp;
	while (ps->pile_b_s > 0)
	{
		nb_ins += next_moove(ps, 1);
		// printf("Liste a\n");
		// pile_show(ps->pile_a);
		// printf("Liste b\n");
		// pile_show(ps->pile_b);
	}
	// printf("Etape 4 finie\n");
	free(sl2);
	nb_ins += last_moove(&ps->pile_a);
	// printf("PILE A\n");
	// pile_show(ps->pile_a);
	// printf("PILE B\n");
	// pile_show(ps->pile_b);
	// printf("Sortie de l'algo\n");
    return (nb_ins);
}
