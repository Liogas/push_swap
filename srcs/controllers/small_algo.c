/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:50:24 by glions            #+#    #+#             */
/*   Updated: 2024/03/26 13:00:27 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	get_moove_next(t_pile *pile, int **moove, int *sl, int i)
{
	if (pile->value == sl[1])
	{
		if (i == 0)
			(*moove)[i] = 1;
		else if (i == 1)
			(*moove)[i] = 0;
		else
			(*moove)[i] = -1;
	}
	else if (pile->value == sl[2])
	{
		if (i == 0)
			(*moove)[i] = -1;
		else if (i == 1)
			(*moove)[i] = 1;
		else
			(*moove)[i] = 0;
	}
}

static int	*get_moove(t_pile *p, int *sl)
{
	int		*moove;
	int		i;
	t_pile	*pile;

	moove = malloc(3 * sizeof(int));
	if (!moove)
		return (NULL);
	pile = p;
	i = 0;
	while (pile)
	{
		if (pile->value == sl[0])
		{
			if (i == 0)
				moove[i++] = 0;
			else if (i == 1)
				moove[i++] = -1;
			else
				moove[i++] = 1;
		}
		else
			get_moove_next(pile, &moove, sl, i++);
		pile = pile->next;
	}
	return (moove);
}

int	small_algo_ps(t_push_swap *ps, int *sl)
{
	int	*moove;

	if (pile_issort(ps->pile_a, sl))
		return (0);
	moove = get_moove(ps->pile_a, sl);
	if (!moove)
		return (-1);
	if (moove[0] == 0)
		return (ins_rr(&ps->pile_a, 1), ins_s(&ps->pile_a, 1), free(moove),
			(2));
	if (moove[0] == -1)
	{
		ins_r(&ps->pile_a, 1);
		if (!pile_issort(ps->pile_a, sl))
			return (free(moove), ins_s(&ps->pile_a, 1), (2));
		return (free(moove), 1);
	}
	if (moove[0] == 1)
	{
		if (moove[2] == 0)
			return (free(moove), ins_s(&ps->pile_a, 1), (1));
		return (free(moove), ins_rr(&ps->pile_a, 1), (1));
	}
	return (-1);
}
