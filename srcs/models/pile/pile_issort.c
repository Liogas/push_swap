/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_issort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:05:37 by glions            #+#    #+#             */
/*   Updated: 2024/02/29 17:07:25 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	pile_issort(t_pile *p, int *exp)
{
	int		i;
	t_pile	*pile;

	pile = p;
	i = 0;
	while (pile)
	{
		if (pile->value != exp[i])
			return (0);
		i++;
		pile = pile->next;
	}
	return (1);
}
