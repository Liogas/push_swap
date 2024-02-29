/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ins_nb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:05:10 by glions            #+#    #+#             */
/*   Updated: 2024/02/29 18:13:17 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	verif_cmp(int nb_ins, int **data)
{
	if (nb_ins < (*data)[0])
	{
		(*data)[0] = nb_ins;
		(*data)[1] = -1;
	}
	else
	{
		(*data)[2] = -1;
		(*data)[3] = -1;
	}
}

void	verif_rrr_rr(int **data, t_pile *p1, t_pile *p2, int t[2])
{
	int	tmp;

	(*data)[0] = get_ins_rr(p1, p2, t[0], t[1]);
	(*data)[2] = -1;
	(*data)[3] = -1;
	if ((*data)[0] != -1)
		(*data)[1] = 3;
	tmp = get_ins_rrr(p1, p1, t[0], t[1]);
	if ((*data)[0] == -1 || ((*data)[0] > tmp && tmp != -1))
	{
		(*data)[0] = tmp;
		(*data)[1] = 4;
	}
}

void	verif_r_rr(int **data, t_pile *p1, t_pile *p2, int t[2])
{
	int	tmp;

	if (ins_cost(p1, t[0], 1) < ins_cost(p1, t[0], 2))
	{
		(*data)[2] = 1;
		tmp = ins_cost(p1, t[0], 1);
	}
	else
	{
		(*data)[2] = 2;
		tmp = ins_cost(p1, t[0], 2);
	}
	if (ins_cost(p2, t[1], 1) < ins_cost(p2, t[1], 2))
	{
		(*data)[3] = 1;
		tmp += ins_cost(p2, t[1], 1);
	}
	else
	{
		(*data)[3] = 2;
		tmp += ins_cost(p2, t[1], 2);
	}
	verif_cmp(tmp, data);
}

int	*get_ins_nb(t_pile *p1, t_pile *p2, int t1, int t2)
{
	int	*data;
	int	t[2];

	data = malloc(4 * sizeof(int));
	if (!data)
		return (NULL);
	t[0] = t1;
	t[1] = t2;
	verif_rrr_rr(&data, p1, p2, t);
	verif_r_rr(&data, p1, p2, t);
	return (data);
}
