/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ins_nb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:05:10 by glions            #+#    #+#             */
/*   Updated: 2024/02/28 15:44:31 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ins_cost(t_pile *p, int	target, int mode)
{
	int	pos;
	
	pos = pile_getpos(target, p);
	if (mode == 1)
		return (pos - 1);
	else
		return (pile_size(p) - pos + 1);
}

static int	get_ins_rrr(t_pile *p1, t_pile *p2, int t1, int t2)
{
	int	ins_p1;
	int	ins_p2;

	ins_p1 = ins_cost(p1, t1, 2);
	ins_p2 = ins_cost(p2, t2, 2);
	if (ins_p1 == 0 && ins_p2 == 0)
		return (-1);
	if (ins_p1 < ins_p2)
		return (ins_p2);
	else
		return (ins_p1);
}

static int	get_ins_rr(t_pile *p1, t_pile *p2, int t1, int t2)
{
	int	ins_p1;
	int	ins_p2;

	ins_p1 = ins_cost(p1, t1, 1);
	ins_p2 = ins_cost(p2, t2, 1);
	if (ins_p1 == 0 && ins_p2 == 0)
		return (-1);
	if (ins_p1 < ins_p2)
		return (ins_p2);
	else
		return (ins_p1);
}

static int	*cost_alone(t_pile *p1, t_pile *p2, int t1, int t2)
{
	int	*data;

	data = malloc(3 * sizeof(int));
	if (!data)
		return (NULL);
	data[0] = ins_cost(p1, t1, 1);
	data[1] = 1;
	if (data[0] > ins_cost(p1, t1, 2))
	{
		data[0] = ins_cost(p1, t1, 2);
		data[1] = 2;
	}
	if (ins_cost(p2, t2, 1) > ins_cost(p2, t2, 2))
	{
		data[2] = 2;
		data[0] += ins_cost(p2, t2, 2);
	}
	else
	{
		data[2] = 1;
		data[0] += ins_cost(p2, t2, 1);
	}
	return (data);
}

static int	*cost_all(t_pile *p1, t_pile *p2, int t1, int t2)
{
	int	*data;
	int	tmp;

	data = malloc(2 * sizeof(int));
	if (!data)
		return (NULL);
	data[0] = get_ins_rr(p1, p2, t1, t2);
	if (data[0] != -1)
		data[1] = 3;
	tmp = get_ins_rrr(p1, p2, t1, t2);
	if (tmp < data[0])
	{
		data[0] = tmp;
		data[1] = 4;
	}
	return (data);
}

int	*get_ins_nb(t_pile *p1, t_pile *p2, int t1, int t2)
{
	int	*data;
	int	*tmp2;
	
	data = malloc(4 * sizeof(int));
	if (!data)
		return (NULL);
	tmp2 = cost_all(p1, p2, t1, t2);
	if (!tmp2)
		return (NULL);
	data[0] = tmp2[0];
	data[1] = tmp2[1];
	data[2] = -1;
	data[3] = -1;
	free(tmp2);
	tmp2 = cost_alone(p1, p2, t1, t2);
	if (!tmp2)
		return (NULL);
	if (data[0] > tmp2[0])
	{
		data[0] = tmp2[0];
		data[1] = -1;
		data[2] = tmp2[1];
		data[3] = tmp2[2];
	}
	return (free(tmp2), data);
}
