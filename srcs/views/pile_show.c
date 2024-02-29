/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_show.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:57:30 by glions            #+#    #+#             */
/*   Updated: 2024/02/29 17:08:26 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pile_show(t_pile *pile)
{
	t_pile	*p;
	int		i;

	p = pile;
	i = 1;
	while (p)
	{
		printf("[%d]->value = %d\n", i, p->value);
		p = p->next;
		i++;
	}
}
