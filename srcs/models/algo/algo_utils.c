/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:18:39 by glions            #+#    #+#             */
/*   Updated: 2024/02/29 18:24:12 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	get_min_pile(t_pile *p)
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

int	*init_data(t_pile *p1, t_pile *p2)
{
	int	*data;

	data = malloc(6 * sizeof(int));
	if (!data)
		return (NULL);
	data[0] = 2147483647;
	data[1] = -1;
	data[2] = -1;
	data[3] = -1;
	data[4] = p1->value;
	data[5] = p2->value;
	return (data);
}

void	update_data(int **data, int value, int target, int *tmp)
{
	(*data)[4] = value;
	(*data)[5] = target;
	(*data)[0] = tmp[0];
	if (tmp[1] != -1)
	{
		(*data)[1] = tmp[1];
		(*data)[2] = -1;
		(*data)[3] = -1;
	}
	else
	{
		(*data)[1] = -1;
		(*data)[2] = tmp[2];
		(*data)[3] = tmp[3];
	}
}

void	mooves_p(t_pile **p, int mode)
{
	if (mode == 1)
		ins_r(p, 1);
	else
		ins_rr(p, 1);
}
