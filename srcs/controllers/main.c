/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:41:45 by glions            #+#    #+#             */
/*   Updated: 2024/02/20 13:20:30 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	printf("Test pile_sort\n");
	ps->pile_c = pile_sort(ps->pile_a);
	if (ps->pile_c)
		pile_show(ps->pile_c);	
	return (push_swap_free(ps), 0);
}
