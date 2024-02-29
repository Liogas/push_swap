/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_target.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:04:10 by glions            #+#    #+#             */
/*   Updated: 2024/02/29 17:06:49 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	get_target_a(int value, t_pile *p)
{
	t_pile	*tmp;
	int		min;
	int		target;
	int		find;

	tmp = p;
	min = tmp->value;
	find = 0;
	while (tmp)
	{
		if (min > tmp->value)
			min = tmp->value;
		if (tmp->value > value && (find == 0 || tmp->value < target))
		{
			find = 1;
			target = tmp->value;
		}
		tmp = tmp->next;
	}
	if (find)
		return (target);
	return (min);
}

int	get_target_b(int value, t_pile *p)
{
	t_pile	*tmp;
	int		max;
	int		target;
	int		find;

	tmp = p;
	max = tmp->value;
	find = 0;
	while (tmp)
	{
		if (max < tmp->value)
			max = tmp->value;
		if (tmp->value < value && (find == 0 || tmp->value > target))
		{
			find = 1;
			target = tmp->value;
		}
		tmp = tmp->next;
	}
	if (find)
		return (target);
	return (max);
}
