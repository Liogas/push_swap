/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:07:58 by glions            #+#    #+#             */
/*   Updated: 2024/02/19 13:03:13 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	pile_free(t_pile *pile)
{
	t_pile	*tmp;

	while (pile)
	{
		tmp = pile->next;
		free(pile);
		pile = tmp;
	}
}
