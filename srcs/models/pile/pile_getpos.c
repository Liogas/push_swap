/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_getpos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:42:19 by glions            #+#    #+#             */
/*   Updated: 2024/02/29 17:07:03 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	pile_getpos(int target, t_pile *p)
{
	int		i;
	t_pile	*tmp;

	i = 1;
	tmp = p;
	while (tmp)
	{
		if (tmp->value == target)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (-1);
}
