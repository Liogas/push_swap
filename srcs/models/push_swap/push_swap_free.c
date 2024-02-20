/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:49:13 by glions            #+#    #+#             */
/*   Updated: 2024/02/20 16:00:28 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push_swap_free(t_push_swap *ps)
{
	if (ps->pile_a)
		pile_free(ps->pile_a);
	if (ps->pile_b)
		pile_free(ps->pile_b);
	free(ps);
}
