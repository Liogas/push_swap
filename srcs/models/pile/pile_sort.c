/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:16:48 by glions            #+#    #+#             */
/*   Updated: 2024/02/20 15:34:12 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// static int	pile_cmp(int a, int b)
// {
// 	return (a > b);
// }

t_pile	*pile_sort(t_pile *p)
{
	t_pile	*pile_c;
	t_pile	*before;
	t_pile	*tmp1;
	t_pile	*next;

	pile_c = p;
	tmp1 = pile_c;
	before = NULL;
	while (tmp1)
	{
		if (tmp1->next)
		{
			next = tmp1->next;
			if (tmp1->value > next->value)
			{
				tmp1->next = next->next;	
				next->next = tmp1;
				if (before)
					before->next = next;
				if (tmp1->value == pile_c->value)
					pile_c = next;
				tmp1 = pile_c;
			}
		}
		before = tmp1;
		tmp1 = tmp1->next;
	}
	return (pile_c);
}
