/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:18:54 by glions            #+#    #+#             */
/*   Updated: 2024/02/22 18:13:36 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_pile	*pile_new(int nb, char id)
{
	t_pile	*new;

	new = malloc(sizeof(t_pile));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->value = nb;
	new->id_pile = id;
	return (new);
}
