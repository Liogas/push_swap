/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:41:45 by glions            #+#    #+#             */
/*   Updated: 2024/03/22 10:58:41 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	algo(t_push_swap *ps)
{
	int	*sl;
	int	nb_ins;

	sl = sort_list(ps->pile_a);
	if (!sl)
		return (0);
	if (pile_issort(ps->pile_a, sl))
		return (free(sl), (0));
	if (pile_size(ps->pile_a) == 2)
	{
		ins_s(&ps->pile_a, 1);
		return (free(sl), 1);
	}
	if (pile_size(ps->pile_a) == 3)
	{
		nb_ins = small_algo_ps(ps, sl);
		if (pile_issort(ps->pile_a, sl))
		{
			return (free(sl), nb_ins);
		}
		return (free(sl), 0);
	}
	return (free(sl), big_algo(ps));
}

int	main(int ac, char **av)
{
	t_push_swap	*ps;

	if (ac < 2)
		return ((1));
	ps = push_swap_new();
	if (!ps)
		return (1);
	if (ac > 2)
	{
		ps->pile_a = parsing_1(ac, av);
		if (!ps->pile_a)
			return (print_error(), push_swap_free(ps), (1));
	}
	else
	{
		ps->pile_a = parsing_2(av[1]);
		if (!ps->pile_a)
			return (print_error(), push_swap_free(ps), (1));
	}
	push_swap_update_size(ps);
	if (ps->pile_a_s < 2)
		return (print_error(), push_swap_free(ps), (1));
	if (algo(ps) == -1)
		return (print_error(), push_swap_free(ps), (1));
	return (push_swap_free(ps), 0);
}
