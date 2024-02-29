/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:53:06 by glions            #+#    #+#             */
/*   Updated: 2024/02/29 17:07:51 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_push_swap	*push_swap_new(void)
{
	t_push_swap	*new;

	new = malloc(sizeof(t_push_swap));
	if (!new)
		return (NULL);
	new->pile_a = NULL;
	new->pile_b = NULL;
	new->pile_a_s = 0;
	new->pile_b_s = 0;
	new->nb_ins = 0;
	return (new);
}
