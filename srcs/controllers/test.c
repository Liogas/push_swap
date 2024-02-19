/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:32:32 by glions            #+#    #+#             */
/*   Updated: 2024/02/19 16:26:14 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	test(t_push_swap *ps)
{
	swap_a(&ps->pile_a, 1);
	push_b(&ps->pile_a, &ps->pile_b, 1);
	push_b(&ps->pile_a, &ps->pile_b, 1);
	push_b(&ps->pile_a, &ps->pile_b, 1);
	rotate_rr(&ps->pile_a, &ps->pile_b, 1);
	reverse_rotate_rrr(&ps->pile_a, &ps->pile_b, 1);
	swap_a(&ps->pile_a, 1);
	push_a(&ps->pile_b, &ps->pile_a, 1);
	push_a(&ps->pile_b, &ps->pile_a, 1);
	push_a(&ps->pile_b, &ps->pile_a, 1);
	printf("Pile A\n");
	pile_show(ps->pile_a);
	printf("Pile B\n");
	pile_show(ps->pile_b);
	return (1);
}
