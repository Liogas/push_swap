/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:10:41 by glions            #+#    #+#             */
/*   Updated: 2024/02/20 16:15:08 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	*sort_list(t_pile *p)
{
	int		*tab;
	t_pile	*tmp;
	int		i;

	tab = malloc(pile_size(p) * sizeof(int));
	if (!tab)
		return (NULL);
	tmp = p;
	i = 0;
	while (tmp)
	{
		tab[i] = tmp->value;
		tmp = tmp->next;
		i++;
	}
	i = 0;
	while (i < pile_size(p) - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			swap(&tab[i], &tab[i + 1]);
			i = -1;
		}
		i++;
	}
	return tab;
}
