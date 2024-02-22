/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_dup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:14:18 by glions            #+#    #+#             */
/*   Updated: 2024/02/22 20:07:02 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_pile	*pile_dup(t_pile *p)
{
	t_pile	*new_p;
	t_pile	*tmp;
	t_pile	*new;
	
	tmp = p;
	new_p = pile_new(tmp->value, 'c');
	if (!new_p)
		return (NULL);
	tmp = tmp->next;
	while (tmp)
	{
		new = pile_new(tmp->value, 'c');
		if (!new)
			return (pile_free(new_p), (NULL));
		pile_addback(&new_p, new);
		tmp = tmp->next;
	}
	return (new_p);
}
