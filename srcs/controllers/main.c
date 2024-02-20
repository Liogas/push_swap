/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:41:45 by glions            #+#    #+#             */
/*   Updated: 2024/02/20 16:32:23 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


static int	start_algo(t_push_swap *ps, int *exp)
{
	int	i;
	int	size;
	int	run;
	t_pile	*tmp;

	i = 0;
	size = pile_size(ps->pile_a);
	run = 1;
	while (run)
	{
		while (pile_size(ps->pile_b) < size)
		{
			tmp = ps->pile_a;
			while (tmp->value != exp[i])
			{
				
			}
		}
	}
}

static int	algo(t_push_swap *ps)
{
	int	*sl;
	int	i;

	sl = sort_list(ps->pile_a);
	if (!sl)
		return (0);
	i = 0;
	sort_show(sl, pile_size(ps->pile_a));
	free(sl);
	return (1);
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
	if (pile_size(ps->pile_a) < 2)
		return (print_error(), push_swap_free(ps), (1));
	if (!algo(ps))
		return (print_error(), push_swap_free(ps), (1));
	return (push_swap_free(ps), 0);
}
