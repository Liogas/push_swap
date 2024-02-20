/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:49:13 by glions            #+#    #+#             */
/*   Updated: 2024/02/20 12:31:45 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push_swap_free(t_push_swap *ps)
{
	if (ps->pile_a)
		pile_free(ps->pile_a);
	if (ps->pile_b)
		pile_free(ps->pile_b);
	if (ps->pile_c)
		pile_free(ps->pile_c);
	free(ps);
}
