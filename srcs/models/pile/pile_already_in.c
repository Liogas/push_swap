/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_already_in.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:04:19 by glions            #+#    #+#             */
/*   Updated: 2024/03/28 13:09:08 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	pile_already_in(t_pile *p, t_pile *n)
{
	t_pile	*tmp;

	tmp = p;
	while (tmp)
	{
		if (tmp->value == n->value)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
