/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:16:48 by glions            #+#    #+#             */
/*   Updated: 2024/02/20 13:23:42 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// static int	pile_cmp(int a, int b)
// {
// 	return (a > b);
// }

t_pile	*pile_sort(t_pile *p)
{
	t_pile	*pile;
	t_pile	*pile_c;
	t_pile	*before;
	t_pile	*tmp;
	t_pile	*tmp2;

	// size = pile_size(p);
	// before = NULL;
	// pile = p;
	// i = 1;
	// while (i < size)
	// {
	// 	tmp = pile->next;
	// }

	pile_c = p;
	pile = pile_c;
	before = NULL;
	while (pile)
	{
		if (pile->next)
		{
			if (pile->value > pile->next->value)
			{
				tmp = pile;
				
			}
		}
		before = pile;
		pile = pile->next;
	}

	// while (pile)
	// {
	// 	if (pile->next)
	// 	{
	// 		if (pile->value > pile->next->value)
	// 		{

	// 		}
	// 	}
	// }



	// while (pile)
	// {
	// 	if (pile->next)
	// 	{
	// 		if (pile_cmp(pile->value, pile->next->value))
	// 		{
	// 			printf("%d > %d\n", pile->value, pile->next->value);
	// 			if (before)
	// 				before->next = pile->next;
	// 			pile->next = pile;
	// 			pile = pile->next;
	// 		}
	// 	}
	// 	before = pile;
	// 	pile = pile->next;
	// }
	return (NULL);
}
